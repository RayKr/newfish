#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
    struct Node *prev;
} Node;

int main()
{
    int m, n;
    scanf("%d %d", &n, &m);
    // 创建循环链表
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->prev = NULL;
    Node *tail = head;
    for (int i = 1; i <= n; i++)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    tail->next = head->next;
    head->next->prev = tail;
    tail = tail->next;
    free(head);

    // 循环删除
    int step = 1;
    Node *p = tail;
    Node *temp;
    while (p->next)
    {
        // 删除符合条件的结点
        if (step % m == 0)
        {
            if (p->next->next == p)
            {
                temp = p;
                p->next->prev = NULL;
                p->prev->next = NULL;
                p = p->prev;
                free(temp);
                break;
            }

            // 删除p
            temp = p;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            p = p->prev;
            free(temp);
        }
        // 步进
        step++;
        p = p->next;
    }

    printf("%d\n", p->data);

    return 0;
}