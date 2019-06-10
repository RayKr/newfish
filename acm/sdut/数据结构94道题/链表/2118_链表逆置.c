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

int main()
{
    int a;
    // 初始化头结点
    Node *L = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L->next = NULL;
    Node *tail = L; // 指向当前尾结点的指针
    // 依次输入并创建链表
    while (scanf("%d", &a), a != -1)
    {
        // 尾插法保证按插入顺序记录
        Node *c = (Node *)malloc(sizeof(Node)); // 申请空间
        c->data = a;                            // 赋值
        c->next = NULL;                         // 新结点的next指针指向NULL
        tail->next = c;                         // 尾结点的next指向该结点
        tail = c;                               // 当前结点变成新的尾结点
    }

    // 遍历链表，再用头插法进行逆置
    Node *N = (Node *)malloc(sizeof(Node));
    Node *cur = L->next;
    while (cur != NULL)
    {
        Node *c = (Node *)malloc(sizeof(Node));
        c->data = cur->data;
        c->next = N->next; // 新结点的next指针指向原头结点
        N->next = c;       // 头结点next指向该结点

        cur = cur->next;
    }

    printLinkedList(N);

    return 0;
}