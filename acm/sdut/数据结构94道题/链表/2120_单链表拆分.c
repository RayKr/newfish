#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

Node *head1, *head2;

int getLinkedListLength(Node *L)
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

void printLinkedList(Node *Head)
{
    Node *cur = Head->next;
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

int split(Node *L)
{
    Node *tail1, *tail2, *p;
    // 初始化
    head1 = L;
    head2 = (Node *)malloc(sizeof(Node));
    head2->next = NULL;
    tail1 = head1;
    tail2 = head2;
    p = L->next;
    // 遍历
    while (p)
    {
        // 判断奇偶
        if (p->data % 2 == 0)
        {
            tail1->next = p; // 串到链尾
            tail1 = p;       // 指针移到链尾
        }
        else
        {
            tail2->next = p;
            tail2 = p;
        }
        // p指针后移
        p = p->next;
    }
    // 还得断开原链中的尾
    tail1->next = NULL;
    tail1->next = NULL;

    return 0;
}

int main()
{
    int m, n, item;
    scanf("%d", &m);
    // 初始化头结点
    Node *L = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L->next = NULL;
    Node *tail = L;
    while (m--)
    {
        scanf("%d", &item);
        // 尾插法保证按插入顺序记录
        Node *c = (Node *)malloc(sizeof(Node)); // 申请空间
        c->data = item;                         // 赋值
        c->next = NULL;                         // 新结点的next指针指向NULL
        tail->next = c;                         // 尾结点的next指向该结点
        tail = c;                               // 当前结点变成新的尾结点
    }

    split(L);
    printf("%d %d\n", getLinkedListLength(head1), getLinkedListLength(head2));
    printLinkedList(head1);
    printLinkedList(head2);

    return 0;
}