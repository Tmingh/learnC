/*************************************************************************
	> File Name: 4-14.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月01日 星期日 17时33分29秒
 ************************************************************************/

#include<stdio.h>
#define swap(t, x, y) {t n;n = x;x = y;y = n;}

int main(void)
{
    int a = 998, b = 1024;
    char c = 'f', d = 'b';
    swap(int, a, b);
    swap(char, c, d);
    printf("%d %d\n", a, b);
    printf("%c %c\n", c, d);
    return 0;
}
