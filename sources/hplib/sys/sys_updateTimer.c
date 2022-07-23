//& ****************************************************************************
//&
//& Written by Chris Smith, January 2005
//&
//& Copyright (C) 2005 The HP-GCC Development Team
//&
//& ****************************************************************************
//&
//& This file is part of HP-GCC.
//&
//& HP-GCC is free software; you can redistribute it and/or modify
//& it under the terms of the GNU General Public License as published by
//& the Free Software Foundation; either version 2, or (at your option)
//& any later version.
//& 
//& HP-GCC is distributed in the hope that it will be useful,
//& but WITHOUT ANY WARRANTY; without even the implied warranty of
//& MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//& GNU General Public License for more details.
//& 
//& You should have received a copy of the GNU General Public License
//& along with HP-GCC; see the file COPYING. 
//&
//& As a special exception, you may use this file as part of a free software
//& library without restriction.  Specifically, if other files instantiate
//& templates or use macros or inline functions from this file, or you compile
//& this file and link it with other files to produce an executable, this
//& file does not by itself cause the resulting executable to be covered by
//& the GNU General Public License.  This exception does not however
//& invalidate any other reasons why the executable file might be covered by
//& the GNU General Public License.
//&
//& ****************************************************************************

#include <hpsys.h>
#include <hpstdio.h>

static unsigned int old_mpllcon = 0;
static unsigned int old_clkslow = 0;
static unsigned int old_clkdivn = 0;

static ULONGLONG univ_mul       = 1;
static unsigned int univ_div    = 1;

static int univ_inited          = 0;

struct pwm_state
{
    unsigned int prescaler, divider;
    unsigned int mul;

    unsigned int inited;
};

static struct pwm_state pwms[5] =
{
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
};

static int init_regs(int n)
{
    unsigned int volatile *MPLLCON = (unsigned int *) 0x7200004;
    unsigned int volatile *CLKSLOW = (unsigned int *) 0x7200010;
    unsigned int volatile *CLKDIVN = (unsigned int *) 0x7200014;

    unsigned int mpllcon = *MPLLCON;
    unsigned int clkslow = *CLKSLOW;
    unsigned int clkdivn = *CLKDIVN;

    if (!univ_inited
        || (mpllcon != old_mpllcon)
        || (clkslow != old_clkslow)
        || (clkdivn != old_clkdivn))
    {
        old_mpllcon = mpllcon;
        old_clkslow = clkslow;
        old_clkdivn = clkdivn;

        univ_mul = univ_div = 1;

        /*
         * PCLK DIVIDERS ---------------------------------------------------
         *
         * There are three internal clocks in the S3C2410X chip.  The clock
         * used by PWM timers is PCLK, and it can be divided several times
         * from the value of the primary clock, FCLK.  Those dividers need to
         * be taken into account.
         */
        unsigned hdivn = (clkdivn >> 1) & 0x01;
        unsigned pdivn = (clkdivn >> 1) & 0x01;

        if (hdivn) univ_mul *= 2;
        if (pdivn) univ_mul *= 2;

        /*
         * FCLK DETERMINANTS -----------------------------------------------
         *
         * The FCLK frequency is determined in one of two ways: slow mode,
         * or normal mode.
         */
        unsigned slow_bit = (clkslow >> 4) & 0x01;

        if (slow_bit)
        {
            /*
             * FCLK: SLOW MODE ---------------------------------------------
             *
             * The input comes from a constant 12 MHz clock.  This can be
             * passed through a divider to reduce the frequency by up to a
             * factor of 14.
             */
            unsigned slow_val = (clkslow >> 0) & 0x07;
            if (slow_val) univ_mul *= slow_val * 2;

            /*
             * The base clock runs as 12 MHz.  That means a period of 250/3
             * nanoseconds per tick of the base clock.
             */
            univ_mul *= 250;
            univ_div *= 3;
        }
        else
        {
            /*
             * FCLK: NORMAL MODE -------------------------------------------
             *
             * The input comes from a constant 12 MHz clock.  This is passed
             * through a phase lock loop (PLL) to increase the frequency to
             * a higher value.  The PLL is controlled by values stored in the
             * MPLLCON register.
             */
            unsigned mdiv = (mpllcon >> 12) & 0xFF;
            unsigned pdiv = (mpllcon >> 4) & 0x3F;
            unsigned sdiv = (mpllcon >> 0) & 0x03;

            unsigned m = mdiv + 8;
            unsigned p = pdiv + 2;
            unsigned s = sdiv;

            univ_mul *= 250 * p * (1 << s);
            univ_div *= 3 * m;
        }

        univ_inited = 1;
    }

    /*
     * PWM TIMER -----------------------------------------------------------
     *
     * The PWM timer input is divided by both a prescaler value and a
     * divider value.  The elapsed time must be multiplied by these same
     * factors.
     */
    unsigned int volatile *TCFG0   = (unsigned int *) 0x7600000;
    unsigned int volatile *TCFG1   = (unsigned int *) 0x7600004;

    unsigned int tcfg0   = *TCFG0;
    unsigned int tcfg1   = *TCFG1;

    unsigned prescaler =
        ((n < 2) ? (tcfg0 & 0xFF) : ((tcfg0 & 0xFF00) >> 8)) + 1;
    unsigned divider = (tcfg1 & (0x0F << (n * 4))) >> (n * 4);

    if (!pwms[n].inited
        || (pwms[n].prescaler != prescaler)
        || (pwms[n].divider != divider))
    {
        pwms[n].prescaler = prescaler;
        pwms[n].divider = divider;

        /*
         * There has been a change in the relevant registers.  Need to
         * recalculate the multipliers or dividers.
         */
        pwms[n].mul = prescaler;
        if (divider < 4) pwms[n].mul <<= (divider + 1);
        else
        {
            /*
             * Input to PWM timers comes from an external hardware clock.
             * This should never be the case for HP calculators.  Bail out
             * now.
             */
            return -1;
        }
    }

    return 0;
}

/*
 * The result of a call to this function is the elapsed time in nanseconds
 * since the previous call.  If there is no previous call, it returns zero.
 *
 * This function must be called frequently in order to work properly.  The
 * underlying hardware timer wraps after a certain amount of time.  That
 * amount of time depends on the CPU speed and the values of numerous dividers
 * and prescalers.  The same factors affect the precision of the function.
 * The information below describes these characteristics for certain common
 * configurations.
 *
 * mode   | sys_setupTimers | wrap interval   | precision
 * -------+-----------------+-----------------+-----------------
 * Slow   | No              | 50 seconds      | 763 microseconds
 * Normal | No              |  8 seconds      | 126 microseconds
 * Slow   | Yes             | 44 milliseconds | 671 nanoseconds
 * Normal | Yes             |  7 milliseconds | 107 nanoseconds
 *
 * It should be clear from the information above that sys_setupTimers
 * dramatically reduces the safe time interval between consecutive calls to
 * this method, but it also improves the precision of the result by the same
 * factor.  Note that it is nearly impossible to make appropriate use of this
 * function when running at normal processor speeds after a call to
 * sys_setupTimers.  Don't even try.
 */
ULONGLONG sys_updateTimer(sys_timer_t *timer)
{
    int n = timer->timer;
    if (init_regs(n)) return 0;

    unsigned tickaddr = 0x7600014;
    if (n < 4) tickaddr += 12 * n;
    else tickaddr = 0x7600040;

    unsigned countaddr = 0x760000C;
    countaddr += 12 * n;

    int newclock = *((unsigned short volatile *) tickaddr);

    if (!timer->inited)
    {
        timer->last_val = newclock;
        timer->current = 0;
        timer->inited = 1;

        return 0;
    }

    int oldclock = timer->last_val;

    ULONGLONG elapsed;

    if (newclock <= oldclock)
    {
        elapsed = oldclock - newclock;
    }
    else
    {
        int count = *((unsigned short volatile *) tickaddr);
        elapsed = oldclock + count - newclock;
    }

    elapsed = elapsed * univ_mul * pwms[n].mul / univ_div;

    /*
     * Update the old clock so that the return value the next time around is
     * counted from the return value of this call.
     */
    timer->last_val = newclock;
    timer->current += elapsed;

    return elapsed;
}
