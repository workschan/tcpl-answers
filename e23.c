/**
 * Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its
 * equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

size_t htoi(char hex[]);

int main(void)
{
    printf("%ld\n", htoi("0X100"));
    return 0;
}

size_t htoi(char hex[])
{
    int i = 0;
    int c = 0;

    // drop prefix 0x or 0X
    if(tolower(hex[1]) == 'x'){
        hex = strchr(hex, hex[2]);
    }

    size_t n = strlen(hex);
    size_t res = 0;
    while((c = hex[i++]) != '\0') {
        if(c >= '0' && c <= '9')
            c = c - '0';
        else if(c >= 'a' && c <= 'f')
            c = 10 + c - 'a';
        else if(c >= 'A' && c <= 'F')
            c = 10 + c - 'A';
        else {
            printf("Error format hexadecimal digits!\n");
            return _NULL;
        }

        res += c * (size_t)pow(16, --n);
    }
    return res;
}
