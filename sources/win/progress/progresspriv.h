#ifndef PROGRESSPRIV_H
#define PROGRESSPRIV_H

/*!
 * \brief Data structure that describes a progress bar.
 */
struct win_progress
{
    /*
     * This field indicates if the progress bar is horizontal (orient = 0) or
     * vertical (orient = 1).  By default, a progress bar is set to horizontal.
     * It always progress from left to right (if horizontal) and bottom to top
     * (if vertical).
     */
    unsigned char orient;

    /*
     * This is the minimum value of the progress bar.  It corresponds to 0%
     * progress. By default, it is set to 0.
     */
    double min;

    /*
     * This is the maximum value of the progress bar.  It corresponds to 100%
     * progress. By default, it is set to 100.
     */
    double max;

    /*
     * The current value of the progress bar.  It is always fenced between the
     * minimum and maximum values above.
     */
    double value;

    /*
     * This increment value is used when the progress bar is configured as a
     * slider, when using the arrow keys.  It determines how much the bar
     * should change for a single key press.
     */
    double inc;

    /*
     * Delay during which an arrow key must be pressed before the start of
     * auto-repeat.
     */
    int first;

    /*
     * Delay used between two repetitions during auto-repeat.
     */
    int next;

    /*
     * Amount by which this progress bar is repeating, right now.
     */
    double repeatval;

    /*
     * Whether the focus cursor should be drawn or not.
     */
    unsigned char cursor_vis;

    /*
     * The event number to be fired when the value of the slider changes.  The
     * event must be register by the application and passed to the progress
     * widget.  If this is set to -1, then no event is fired.
     */
    int event;
};

#endif
