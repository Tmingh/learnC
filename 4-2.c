/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月31日 星期六 11时00分26秒
***********************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
long double atof(char s[]);
int main(void)
{
    char ch[20];
    double m;
    gets(ch);
    m = atof(ch);
    printf("%f", m);
    return 0;
}

long double atof(char s[])
{
    long double val, powerl, e;
    int i, sign1, sign2;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign1 = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (powerl = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        powerl *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        sign2 = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (e = 0.0; isdigit(s[i]); i++)
        {
            e = 10.0 * e + (s[i] - '0');
        }
    return sign1 * val / powerl * pow(10,sign2 * e);
    }
    return sign1 * val /powerl;
}

