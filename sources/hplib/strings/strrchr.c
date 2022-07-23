#include <kos.h>
#include <hpstring.h>

/* Added by Al Borowski, 19th Nov 2004
*
* Code taken from http://en.wikibooks.org/wiki/Programming%3AC_strings
* Code was in Public Domain
*/


/* strrchr */
char *(strrchr)(const char *s, int c)
{
    const char *last = NULL;
    /* If the character we're looking for is the terminating null,
       we just need to look for that character as there's only one
       of them in the string.  */
    if (c == '\0')
        return strchr(s, c);
    /* Loop through, finding the last match before hitting NULL.  */
    while ((s = strchr(s, c)) != NULL) {
        last = s;
        s++;
    }
    return (char *) last;
}
