#include <kos.h>
#include <hpstring.h>
#include <hpstdlib.h>

/* Added by Al Borowski, 19th Nov 2004
*
* Code taken from http://en.wikibooks.org/wiki/Programming%3AC_strings
* Code was in Public Domain
*/


/* strstr */
char *(strstr)(const char *s1, const char *s2)
{
    size_t s2len;
    /* Check for the null s2 case.  */
    if (*s2 == '\0')
        return (char *) s1;
    s2len = strlen(s2);
    for (; (s1 = strchr(s1, *s2)) != NULL; s1++)
        if (memcmp(s1, s2, s2len) == 0)
            return (char *) s1;
    return NULL;
}
