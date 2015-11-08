/*************************************************************************
	> File Name: 5-13.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月03日 星期二 18时22分20秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines, int n);
void writelines(char *lineptr[], int nlines, int n);
int main(int argc, char *argv[])
{
    int nlines, n, i;
    if (argv[1][0] == '-' && argc > 0)
    {
        for (i = 1, n = 0; isdigit(argv[1][i]); i++) 
            n = n * 10 + argv[1][i] - '0';
        for (i = 1; !isdigit(argv[1][i]) && argv[1][i] != '\0'; i++)
            n = -1;
        if ((nlines = readlines(lineptr, MAXLINES, n)) >= 0)
            writelines(lineptr, nlines, n);
        else
            printf("Silly B !!!");
        return 0;
    }
    else{
        printf("Silly B !!!");
        return -1;
    }
}
#define MAXLEN 1000
char *alloc(int);
int gtline(char s[], int lim);
int readlines(char *lineptr[], int maxlines, int n)
{
    int len, nlines;
    char *p, line[MAXLEN];
    if (n <= 0)
        return -1;
    else{
        nlines = 0;
        while ((len = gtline(line, MAXLEN)) > 0)
            if (nlines >= maxlines || (p = alloc(len)) == NULL)
                return -1;
            else {
                line[len - 1] = '\0';
                strcpy(p, line);
                lineptr[nlines++] = p;
            }
            return nlines;
    }
}

int gtline(char s[],int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }else
        return 0;
}

void writelines(char *lineptr[], int nlines, int n)
{
    int i;

    for (i = nlines - n; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

