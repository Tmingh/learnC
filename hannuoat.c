/*************************************************************************
	> File Name: hannuoat.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月05日 星期四 07时01分44秒
 ************************************************************************/

#include<stdio.h>
long long hannuota(int n, char a, char b, char c);
int main(void)
{
    int n = 64;
    char a = 'A', b = 'B', c = 'C';
    long long m;
    m = hannuota(n, a, b, c);
}

long long hannuota(int n, char a, char b, char c)
{
    long long total;
    if (n > 0){
        hannuota(n - 1, a, c, b);
        printf("第%d个盘子：%c到%c\n", n, a, c);
        hannuota(n - 1, b, a, c);
    }
    return total;
}
