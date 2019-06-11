#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

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

int sortInsert(Node *L, ElemType e)
{
    Node *tail = L;
    while (tail) // 后边没了，或者后边的比e大，则在此位置插入
    {
        if (!tail->next || tail->next->data >= e)
        {
            Node *node = (Node *)malloc(sizeof(Node));
            node->data = e;
            node->next = tail->next;
            tail->next = node;
            break;
        }

        tail = tail->next;
    }
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
        sortInsert(L, item);
    }
    printLinkedList(L);

    return 0;
}