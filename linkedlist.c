#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80
struct weapon{
    char name[SIZE];
    int atk;
    struct weapon *next;
};

void deleted (struct weapon *);
void insert(struct weapon *);
int main(void)
{
    struct weapon *head;
    struct weapon *p1, *p2;
    char input[SIZE], ch;
    puts("输入第一个武器名:");
    head = (struct weapon *)malloc(sizeof (struct weapon));
    head->next = NULL;
    while (gets(input) != NULL && input[0] != '\0')
    {
        p1 = (struct weapon *)malloc(sizeof (struct weapon));
        if (head->next == NULL)
            head->next = p1;
        else
            p2->next = p1;
        p1->next = NULL;
        strcpy(p1->name, input);
        puts("输入武器的攻击力:");
        scanf("%d",&p1->atk);
        while (getchar() != '\n')
            continue;
        puts("输入下一个武器名(输入空的名字以结束):");
        p2 = p1;
    }
    if (head->next == NULL)
        printf("无数据输入。");
    else{
        puts("你需要删除或增加某些武器的数据吗?(d/i/others)");
        if ((ch=getchar()) == 'd' || ch == 'D')
            deleted(head);
        else if (ch == 'i' || ch == 'I')
            insert(head);
        printf("下面是你的武器列表:\n");
    }
    p1 = head->next;
    while (p1 != NULL)
    {
        printf("武器名:%s   攻击力:%d\n", p1->name, p1->atk);
        p1 = p1->next;
    }
    return 0;
}
struct weapon * find(char *s, struct weapon *head);
void deleted(struct weapon *head)
{
    struct weapon *p, *temp;
    char s[SIZE];
    while (getchar() != '\n')
        continue;
    printf("输入你想删除的武器的名字(输入空的名字以结束):\n");
    while (gets(s) != NULL && s[0] != '\0'){
        p = find(s, head);
        if (p->next != NULL){
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        printf("输入下一个你想删除的武器的名字(输入空的名字以结束):\n");
    }
}
void insert(struct weapon *head)
{
    struct weapon *p, *temp;
    char s[SIZE], input[SIZE];
    while (getchar() != '\n')
        continue;
    printf("你想把第一个新增数据放在哪个武器数据之前?(输入空的名字以结束):\n");
    while (gets(s) != NULL && s[0] != '\0'){
        temp = (struct weapon *)malloc(sizeof (struct weapon));
        p = find(s, head);
        if (p->next != NULL){
            printf("输入新增的武器名：\n");
            gets(input);
            strcpy(temp->name, input);
            printf("输入新增的武器攻击力:\n");
            scanf("%d", &temp->atk);
            while (getchar() != '\n')
                continue;
            temp->next = p->next;
            p->next = temp;
        }
        printf("你想把下一个新增数据放在哪个武器数据之前？(输入空的名字以结束)：\n");
    }
}
struct weapon * find(char *s, struct weapon *head)
{
    struct weapon *p;
    p = head;
    while (p->next != NULL && strcmp(p->next->name, s))
        p = p->next;
    return p;
}
