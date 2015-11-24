/**
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed exponent.
 */

#include <stdio.h>
#include <math.h>

#define MAXLINE 100

/* rudimentary calculator */
main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getline2(char line[], int max);
    sum = 0;
    while (getline2(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[]) {
    double val, dec;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (dec = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        dec *= 10;
    }

    // calculate exponent
    if (s[i] == 'e' || s[i] == 'E') {
        int e_sign = s[++i];
        int exponent;
        i++;
        for (exponent = 0; isdigit(s[i]); i++) {
            exponent = 10 * exponent + (s[i] - '0');
        }
        if (e_sign == '-')
            val /= pow(10, exponent);
        else
            val *= pow(10, exponent);
    }

    return sign * val / dec;
}

/* getline: get line into s, return length */
int getline2(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
