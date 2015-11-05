/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月01日 星期日 15时56分16秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>

void reverse(char s[], int a, int b);
int main(void)
{
    int i, j;
    char ch[1000];
    gets(ch);
    i = 0;
    j = strlen(ch) - 1;
    reverse(ch, i, j);
    printf("%s", ch);
    return 0;
}

void reverse(char s[], int a, int b)
{
    int c;
    if(a < b){
        c = s[a];
        s[a] = s[b];
        s[b] = c;
        reverse(s, ++a, --b);
    }
}

