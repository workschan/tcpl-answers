/**
 * Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 where any character from the
 * string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but
 * returns a pointer to the location.)
 */
 
#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s[] = "abc123";
    printf("the length is %ld\n", strlen(s));
    char t[] = "bc23";
    squeeze(s, t);
    printf("the result is %s\n", s);
    printf("the length is %ld\n", strlen(s));
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i = 0;
    int k = 0;
    char c;
    while ((c = s1[i]) != '\0') {
        int j = 0;
        int matched = 0;
        while (s2[j] != '\0') {
            if (s2[j] == c) {
                matched = 1;
                break;
            }
            j++;
        }
        if (!matched) {
            s1[k++] = c;
        }
        i++;
    }
    s1[k] = '\0';
}
