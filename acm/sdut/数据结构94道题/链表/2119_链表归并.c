#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;     // 单链表数据域
    struct Node *next; // 单链表指针域
} Node, *LinkedList;

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

LinkedList merge(LinkedList L1, LinkedList L2)
{
    Node *p1, *p2, *tail;
    p1 = L1->next;
    p2 = L2->next;
    tail = L1;
    free(L2);
    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
        }
        else
        {
            tail->next = p2;
            tail = p2;
            p2 = p2->next;
        }
    }
    if (p1)
        tail->next = p1;
    else
        tail->next = p2;

    return L1;
}

int main()
{
    int m, n, item;
    scanf("%d %d", &m, &n);
    // 初始化头结点
    Node *L1 = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L1->next = NULL;
    Node *L2 = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L2->next = NULL;
    Node *t1 = L1;
    Node *t2 = L2;
    while (m--)
    {
        scanf("%d", &item);
        // 尾插法保证按插入顺序记录
        Node *c = (Node *)malloc(sizeof(Node)); // 申请空间
        c->data = item;                         // 赋值
        c->next = NULL;                         // 新结点的next指针指向NULL
        t1->next = c;                           // 尾结点的next指向该结点
        t1 = c;                                 // 当前结点变成新的尾结点
    }
    while (n--)
    {
        scanf("%d", &item);
        // 尾插法保证按插入顺序记录
        Node *c = (Node *)malloc(sizeof(Node)); // 申请空间
        c->data = item;                         // 赋值
        c->next = NULL;                         // 新结点的next指针指向NULL
        t2->next = c;                           // 尾结点的next指向该结点
        t2 = c;                                 // 当前结点变成新的尾结点
    }

    LinkedList turn = merge(L1, L2);
    printLinkedList(L1);

    return 0;
}