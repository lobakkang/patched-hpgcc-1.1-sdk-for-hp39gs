#include <kos.h>
#include <hpstring.h>

/* Added by Al Borowski, 19th Nov 2004
*
* Code taken from http://en.wikibooks.org/wiki/Programming%3AC_strings
* Code was in Public Domain
*/


/* strtok_r */
char *(strtok_r)(char *s, const char *sep, char **lasts)
{
    char *sbegin, *send;
    sbegin = s ? s : *lasts;
    sbegin += strspn(sbegin, sep);
    if (*sbegin == '\0') {
        *lasts = "";
        return NULL;
    }
    send = strpbrk(sbegin, sep);
    if (*send != '\0')
        *send++ = '\0';
    *lasts = send;
    return sbegin;
}
/* strtok */
char *(strtok)(char *s1, const char *s2)
{
    static char *ssave = "";
    return strtok_r(s1, s2, &ssave);
}
