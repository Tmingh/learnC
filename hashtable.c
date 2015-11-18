/*************************************************************************
	> File Name: hashtable.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 18时09分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40
struct elements{
    char name[MAX];
    int num;
    struct elements *next;
}elem;//存储元素的结构体

struct tabnode{
    int key;
    struct tabnode *node;
    struct elements *enter;
}table;//散表的主体部分

struct tabnode * hashbuild()
{
    struct tabnode *first, *p1, *p2;
    struct elements *head;
    int i;
    first = (struct tabnode *)malloc(sizeof(struct tabnode));
    head = (struct elements *)malloc(sizeof(struct elements));
    head->next = NULL;
    first->key = 0;
    first->enter = head;
    p1 = (struct tabnode *)malloc(sizeof(struct tabnode));
    first->node = p1;
    for (i = 1; i < 11; i++){
        head = (struct elements *)malloc(sizeof(struct elements));
        head->next = NULL;
        if (i == 10){
            p1->key = i;
            p1->node = NULL;
            p1->enter = head;
        }
        else{
            p1->key = i;
            p2 = (struct tabnode *)malloc(sizeof(struct tabnode));
            p1->node = p2;
            p1->enter = head;
            p1 = p2;
        }
    }
    return first;
}//构建散表

struct elements * find(int i, struct tabnode *h)
{
    struct tabnode *p1;
    struct elements *p2;
    int ele_key;
    p1 = h;
    ele_key = i % 10;
    while (p1 != NULL && p1->key != ele_key)
        p1 = p1->node;
    p2 = p1->enter;
    while (p2->next != NULL && p2->next->num != i)
        p2 = p2->next;
    if (p2->next == NULL)
        return NULL;
    else
        return p2;
}

void insert(int i, char name[], struct tabnode *h)
{
    struct elements *temp, *fid;
    struct tabnode *tonode;
    int ele_key;
    tonode = h;
    ele_key = i % 10;
    fid = find(i, h);
    if (fid != NULL){
        printf("已存在相同的编号\n");
        return;
    }
    else{
        while (tonode != NULL && tonode->key != ele_key)
            tonode = tonode->node;
        temp = (struct elements *)malloc(sizeof(struct elements));
        if (temp == NULL)
            printf("meerror.\n");
        temp->num = i;
        strcpy(temp->name, name);
        temp->next = tonode->enter->next;
        tonode->enter->next = temp;
    }
}

void deleted(int i, struct tabnode *h)
{
    struct elements *n, *temp;
    n = find(i, h);
    if (n == NULL){
        printf("不存在此编号\n");
        return;
    }
    if (n->next != NULL){
        temp = n->next;
        n->next = temp->next;
        free(temp);
    }
}
void output(struct tabnode *hash)
{
    struct elements *p;
    int flag, input;
    puts("请输入你要查询的编号(输入其他字符以结束):");
    flag = scanf("%d", &input);
    while (flag == 1){
        p = find(input, hash);
        if (p == NULL)
            printf("不存在此编号\n");
        else
            printf("名字:%s\n", p->next->name);
        printf("输入下一个要查询的编号(输入其他字符以结束):\n");
        flag = scanf("%d", &input);
        while (getchar() != '\n')
            continue;
    }
}
int main(void)
{
    int input, flag;
    char inputname[MAX], ch;
    struct tabnode *hash;
    struct elements *n;
    hash = hashbuild();
    printf("输入名字:\n");
    while (gets(inputname) != NULL && inputname[0] != '\0')
    {
        printf("请输入编号:\n");
        flag = scanf("%d", &input);
        while (getchar() != '\n')
            continue;
        while (flag != 1){
            printf("输入错误，请输入一个数字:\n");
            flag = scanf("%d", &input);
            while (getchar() != '\n')
                continue;
        }
        insert(input, inputname, hash);
        puts("输入下一个名字(输入空的名字以结束):");
    }
    puts("你需要删除或增加数据吗？(d/i/others)");
    if ((ch=getchar()) == 'd' || ch == 'D'){
        puts("输入你想删除的编号(输入其他字符以结束):");
        flag = scanf("%d", &input);
        while (getchar() != '\n')
            continue;
        while (flag == 1){
            deleted(input, hash);
            printf("输入下一个你想删除的编号(输入其他字符以结束):\n");
            flag = scanf("%d", &input);
            while (getchar() != '\n')
                continue;
        }
        printf("删除结束\n");
    }
    else if (ch == 'i' || ch == 'I'){
        printf("输入新增的名字:\n");
        while (getchar() != '\n')
            continue;
        while (gets(inputname) != NULL && inputname[0] != '\0')
        {
            printf("请输入编号:");
            flag = scanf("%d", &input);
            while (getchar() != '\n')
                continue;
            while (flag != 1){
                printf("输入错误，请输入一个数字:\n");
                flag = scanf("%d", &input);
                while (getchar() != '\n')
                    continue;
            }
        insert(input, inputname, hash);
        puts("输入下一个名字(输入空的名字以结束):");
        }
        printf("插入结束\n");
    }
    output(hash);
    return 0;
}
