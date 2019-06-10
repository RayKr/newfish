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
    int n, a, d;
    // 初始化头结点
    Node *L = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L->next = NULL;
    // 依次输入并创建链表
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        // 尾插法保证按插入顺序记录
        Node *c = (Node *)malloc(sizeof(Node));
        c->data = a;
        c->next = L->next; // 新结点的next指针指向原头结点
        L->next = c;       // 头结点next指向该结点
    }
    printLinkedList(L);

    return 0;
}