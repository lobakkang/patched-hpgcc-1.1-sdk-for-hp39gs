/*! \mainpage HPGCC Standard Library
 *
 * The HPGCC standard library contains basic code for writing applications to
 * run on the calculator.  It consists of all of the following:
 *
 * - A simplified version of most parts of the C language standard library.
 * - Routines for interacting with the calculator hardware (interrupts,
 *   timers, buzzer, LCD controller, etc.)
 * - Low-level routines for reading from the calculator keyboard.
 * - Very simple screen graphics routines.
 * - An exposed interface to the underlying KOS operating system calls (for
 *   advanced users only)
 * - Routines to interact with data from the calculator stack, as well as
 *   other aspects of the emulated Saturn environment.
 */

/*!
 * \file  hpgcc49.h
 * \brief Umbrella header file for the HPGCC standard library.
 *
 * This header file can be used to include the entirety of the HPGCC standard
 * library.  It defines no unique interfaces of its own, and is provided
 * merely as a convenience.
 */
#ifndef _HPGCC49_ALL
#define _HPGCC49_ALL

//includes everything for the HP49g+


// 64-BIT TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05

#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif

#include <hpconio.h>
#include <hpctype.h>
#include <hpkeyb49.h>
#include <hpmath.h>
#include <hpscreen.h>
#include <hpstdio.h>
#include <hpstdlib.h>
#include <hpstring.h>
#include <hpsys.h>
#include <hptime.h>
#include <kos.h>
#include <syscall.h>
#include <saturn.h>

#endif
