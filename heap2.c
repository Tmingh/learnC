/*************************************************************************
	> File Name: heap2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月15日 星期日 07时50分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct heapnode{
    int num;
    int key;
    struct heapnode *next;
};

int i = 0;
void createheap(struct heapnode * head);
struct heapnode * find(int key, struct heapnode *head)
{
    struct heapnode *p;
    p = head;
    while (p->next != NULL && p->next->key != key)
        p = p->next;
    return p;
}
struct heapnode *num_find(int num, struct heapnode *head)
{
    struct heapnode *p;
    p = head;
    while (p->next != NULL && p->next->num != num)
        p->next;
    return p;
}
struct heapnode * createtree()
{
    int temp = 0;
    int a[1000];
    struct heapnode *p1, *p2, *head;
    head = (struct heapnode *)malloc(sizeof(struct heapnode));
    head->key = 0;
    head->next = NULL;
    printf("输入多个数字以建立二叉堆:\n");
    do{
        scanf("%d", &a[i++]);
        printf ("6666666\n");
    }while(getchar() != '\n');
    printf(">>>input working\n");
    while (temp < i){
        p1 = (struct heapnode *)malloc(sizeof(struct heapnode));
        if (head->next == NULL)
            head->next = p1;
        else
            p2->next =p1;
        p1->next =NULL;
        p1->num = a[temp];
        p1->key = temp + 1;
        p2 = p1;
        temp++;
    }
    printf(">>>while working\n");
    return head;
}
void createheap(struct heapnode * head)
{
    int n, m;
    int temp;
    int *swap1,*swap2;
    struct heapnode *p1, *p2;
    m = i;
    for (n = 1; pow (2, n) <= m; n++)
        ;
    printf(">>>first for working\n");
    for( ; n > 0; n--){
        m = i;
        while (m > 1)
        {
            printf(">>>2333\n");
            p1 = find(m, head);
            printf(">>>456\n");
            p2 = find(m/2, head);
            swap1 = &(p1->next->num);
            swap2 = &(p2->next->num);
            if (*swap1 < *swap2){
                temp = *swap1;
                *swap1 = *swap2;
                *swap2 = temp;
            }
            m--;
            printf(">>>while\n");
        }
        printf(">>>while working\n");
    }
    printf(">>>second for working\n");
}
void insert(struct heapnode *head)
{
    int temp;
    struct heapnode *ins_node, *endbe, *end;
    printf("输入你想插入的数字(输入其他字符以结束):");
    while ((scanf("%d", &temp)) == 1){
        endbe = find(i, head);
        end = endbe->next;
        ins_node = (struct heapnode *)malloc(sizeof(struct heapnode));
        ins_node->num = temp;
        ins_node->key = ++i;
        ins_node->next = NULL;
        end->next = ins_node;
        createheap(head);
        printf(">>>zxc\n");
        printf("输入下一个插入的数字(输入其他字符以结束):");
    }
    printf("插入结束");
}
void deleted(struct heapnode *head)
{
    int del_ele;
    struct heapnode *targetbe, *new_struct, *emtybe;
    printf("输入你想删除的数字(输入其他字符以结束):");
    while ((scanf("%d", &del_ele)) == 1)
    {
        targetbe = num_find(del_ele, head);
        if (targetbe->next == NULL)
            printf("无此数字!");
        else{
            new_struct = (struct heapnode *)malloc(sizeof(struct heapnode));
            new_struct->key = targetbe->next->key;
            new_struct->next = targetbe->next->next;
            new_struct->num = 65536;
            targetbe->next = new_struct;
            createheap(head);
            --i;
            emtybe = find(i+1, head);
            free(emtybe->next);
            emtybe->next = NULL;
            printf("输入下一个删除的数字(输入其他字符以结束):");
        }
    }
}
int main(void)
{
    char ch;
    struct heapnode *head, *print;
    head = createtree();
    printf(">>>createtree working\n");
    createheap(head);
    printf("%d", i);
    printf(">>>createheap working\n");
    printf("你需要插入或删除一个数字吗？(i/d/others)\n");
    while (getchar() != '\n')
        continue;
    if((ch=getchar()) == 'i' || ch == 'I'){
        insert(head);
        printf(">>>insert working\n");
    }
    else if (ch == 'd' || ch == 'D'){
        deleted(head);
        printf(">>>deleted working\n");
    }
    print = head->next;
    while (print != NULL)
    {
        printf("%d\n", print->num);
        print = print->next;
    }
    return 0;
}
