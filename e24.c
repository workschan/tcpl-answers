/**
 * Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in
 * the string s2.
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
