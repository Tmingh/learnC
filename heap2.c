/*************************************************************************
	> File Name: heap2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月15日 星期日 07时50分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
struct heapnode{
    int num;
    int key;
    struct heapnode *next;
};

int i = 0;
int n;
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
        p = p->next;
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
    }while(getchar() != '\n');
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
    return head;
}
void createheap(struct heapnode * head)
{
    int m, q;
    int temp;
    int *swap1,*swap2;
    struct heapnode *p1, *p2;
    m = i;
    for (n = 1; pow (2, n) <= m; n++)
        ;
    q = n;
    for( ; q > 0; q--){
        m = i;
        while (m > 1)
        {
            p1 = find(m, head);
            p2 = find(m/2, head);
            swap1 = &(p1->next->num);
            swap2 = &(p2->next->num);
            if (*swap1 < *swap2){
                temp = *swap1;
                *swap1 = *swap2;
                *swap2 = temp;
            }
            m--;
        }
    }
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
        printf("输入下一个插入的数字(输入其他字符以结束):");
    }
    printf("插入结束");
}
void deleted(struct heapnode *head)
{
    int del_ele;
    struct heapnode *targetbe, *p, *emtybe, *temp;
    printf("输入你想删除的数字(输入其他字符以结束):");
    while ((scanf("%d", &del_ele)) == 1)
    {
        targetbe = num_find(del_ele, head);
        if (targetbe->next == NULL)
            printf("无此数字!");
        else{
            p = targetbe->next;
            while (p->next != NULL){
                p = p->next;
                p->key = p->key - 1;
            }
            temp = targetbe->next;
            targetbe->next = targetbe->next->next;
            free(temp);
            i--;
            createheap(head);
            printf("输入下一个删除的数字(输入其他字符以结束):");
        }
    }
}
void print(struct heapnode *head)
{
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 1; j <= pow(2, i); j++){
            head = head->next;
            if (head == NULL)
                break;
            printf("%6d", head->num);
        }
        putchar('\n');
    }
}
int main(void)
{
    char ch;
    struct heapnode *head;
    head = createtree();
    createheap(head);
    printf("你需要插入或删除一个数字吗？(i/d/others)\n");
    if((ch=getchar()) == 'i' || ch == 'I'){
        insert(head);
    }
    else if (ch == 'd' || ch == 'D'){
        deleted(head);
    }
    print(head);
    return 0;
}
