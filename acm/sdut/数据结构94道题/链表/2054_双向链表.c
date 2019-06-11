#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *prev;
    struct Node *next;
} Node;

int searchItem(Node *L, ElemType e)
{
    Node *p = L->next;
    while (p)
    {
        if (p->data == e)
        {
            if (p->next && p->prev && p->prev != L)
            {
                printf("%d %d", p->prev->data, p->next->data);
            }
            else if (p->next)
            {
                printf("%d", p->next->data);
            }
            else if (p->prev && p->prev != L)
            {
                printf("%d", p->prev->data);
            }
            printf("\n");
            break;
        }
        p = p->next;
    }

    return 0;
}

int main()
{
    int m, n, item, a;
    scanf("%d %d", &m, &n);
    // 创建链表
    Node *L = (Node *)malloc(sizeof(Node));
    L->prev = NULL;
    L->next = NULL;
    Node *tail = L;
    while (m--)
    {
        scanf("%d", &item);
        // 尾插法创建双向链表
        Node *n = (Node *)malloc(sizeof(Node));
        n->data = item;
        n->prev = tail;
        n->next = NULL;
        tail->next = n;
        tail = n;
    }

    while (n--)
    {
        scanf("%d", &a);
        searchItem(L, a);
    }

    return 0;
}