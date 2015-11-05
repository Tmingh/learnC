/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月03日 星期二 14时37分34秒
 ************************************************************************/
//目前包含5-14和5-15
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelinesn(char *lineptr[], int nlines);
void writelinesr(char *lineptr[], int nlines);

void qsortm(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int ftcmp(char *, char *);
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int i, r = 0;
    int (*functe)(void *, void *);
    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'n')
                numeric = 1;
            if (argv[i][1] == 'r')
                r = 1;
            if (argv[i][1] == 'f')
                numeric = -1;
        }
    }
    if (numeric == 0)
        functe = &strcmp;
    else if (numeric == 1)
        functe = &numcmp;
    else if (numeric == -1)
        functe = &ftcmp;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsortm((void **)lineptr, 0, nlines - 1, (int (*)(void *,void *))(functe));
        (r ? writelinesr : writelinesn)(lineptr, nlines);
        return 0;
    }
    else{
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int tline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = tline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

int tline(char s[],int lim)
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

void writelinesn(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
void writelinesr(char *lineptr[], int nlines)
{
    int i;
    for (i = nlines - 1; i >= 0; i--)
        printf("%s\n", lineptr[i]);
}

void qsortm(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsortm(v, left, last - 1, comp);
    qsortm(v, last + 1, right, comp);
}
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
int ftcmp(char *s1, char *s2)
{
    char n, m;
    if (isalpha(*s1) && isalpha(*s2)){
        if (isupper(*s1))
            n = 32 + *s1;
        else
            n = *s1;
        if (isupper(*s2))
            m = 32 + *s2;
        else
            n = *s2;
        if (n < m)
            return -1;
        else if (n > m)
            return 1;
        else
            return 0;
    }
    else{
        if (*s1 < *s2)
            return -1;
        else if (*s1 > *s2)
            return 1;
        else 
            return 0;
    }
}
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
