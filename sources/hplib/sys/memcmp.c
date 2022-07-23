#include <hpstdlib.h>
/* Added by Al Borowski, 19th Nov 2004
*
* Code taken from http://en.wikibooks.org/wiki/Programming%3AC_strings
* Code was in Public Domain
*/



/* memcmp */
int (memcmp)(const void *s1, const void *s2, size_t n)
{
    unsigned char *us1 = (unsigned char *) s1;
    unsigned char *us2 = (unsigned char *) s2;
    while (n-- != 0) {
        if (*us1 != *us2)
            return (*us1 < *us2) ? -1 : +1;
        us1++;
        us2++;
    }
    return 0;
}
