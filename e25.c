/**
 * Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 where any character from the
 * string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but
 * returns a pointer to the location.)
 */

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s[] = "a2cb";
    char t[] = "debkj";
    printf("the first location is %d\n", any(s, t));
    return 0;
}

int any(char s1[], char s2[])
{
    int i;
    int j;
    int loc = -1;
    i = 0;
    while (loc == -1 && s1[i] != '\0') {
        j = 0;
        while (loc == -1 && s2[j] != '\0') {
            if (s1[i] == s2[j])
                loc = i;
            j++;
        }
        i++;
    }
    return loc;
}
