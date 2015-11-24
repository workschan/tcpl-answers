/**
 * Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if
 * there is none.
 */

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main()
{
    int i;
    char s[] = "This is a test string.";
    char t[] = "is";
    i = strrindex(s, t);
    printf("%d\n", i);
    return 0;
}

int strrindex(char s[], char t[])
{
    int i, j, k, pos;
    int ls = strlen(s);
    int lt = strlen(t);

    for (i = ls-1; i>=0; i--)
    {
        if (s[i] == t[lt-1]) {
            pos = i-lt+1;
            for (j=pos, k=0; j>-1 && t[k]!='\0' && s[j]==t[k]; j++, k++)
                ;
            if (k > 0 && t[k] == '\0')
                return pos;
        }
    }
    return -1;
}
