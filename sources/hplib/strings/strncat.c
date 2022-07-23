#include <kos.h>
#include <hpstring.h>

/* Added by Al Borowski, 19th Nov 2004
*
* Code taken from http://en.wikibooks.org/wiki/Programming%3AC_strings
* Code was in Public Domain
*/

/* strncat */
char *(strncat)(char *s1, const char *s2, size_t n)
{
    char *s = s1;
    /* Loop over the data in s1.  */
    while (*s != '\0')
        s++;
    /* s now points to the its trailing null character, now copy
       up to n bytes from s2 into s1 stopping if a NULL is encountered
       in s2.
       It is not safe to use strncpy here since it copies EXACTLY n
       characters, NULL padding if necessary.  */
    while (n != 0 && (*s = *s2++) != '\0') {
        n--;
        s++;
    }
    if (*s != '\0')
        *s = '\0';
    return s1;
}
