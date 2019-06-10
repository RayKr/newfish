#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;     // 单链表数据域
    struct Node *next; // 单链表指针域
} Node, *LinkedList;

int getLinkedListLength(LinkedList L)
{
    int count = 0;
    Node *cur = L->next;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

void printLinkedList(LinkedList L)
{
    Node *cur = L->next;
    while (cur != NULL)
    {
        printf("%d", cur->data);
        cur = cur->next;
        // 此处的空格，如果行尾有空格，会报Presentation Error
        if (cur != NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int checkDeplicate(LinkedList L, Node *node)
{
    Node *cur = L->next;
    while (cur != NULL && cur != node)
    {
        if (cur->data == node->data)
        {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

int main()
{
    int n, a, d;
    // 初始化头结点
    Node *L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    Node *tail = L;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        // 头插法实现逆序
        Node *c = (Node *)malloc(sizeof(Node));
        c->data = a;
        c->next = L->next; // 新结点的next指针指向原头结点
        L->next = c;       // 头结点next指向该结点
    }
    printf("%d\n", getLinkedListLength(L));
    printLinkedList(L);

    // 删除重复数据
    Node *cur = L;
    while (cur->next != NULL)
    {
        if (checkDeplicate(L, cur->next))
        {
            // 删掉该结点
            Node *temp = cur->next->next;
            free(cur->next);
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    printf("%d\n", getLinkedListLength(L));
    printLinkedList(L);

    return 0;
}