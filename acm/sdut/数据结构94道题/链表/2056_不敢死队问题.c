#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
    struct Node *prev;
} Node;

int getSort(int n)
{
    // 创建n的循环列表
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
    int s = 0;
    while (p)
    {
        // 删除符合条件的结点
        if (step % 5 == 0)
        {
            if (p->data == 1)
            {
                s++;
                break;
            }

            // 删除p
            temp = p;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            p = p->prev;
            free(temp);

            s++;
        }
        // 步进
        step++;
        p = p->next;
    }

    return s;
}

int main()
{
    int a, s;
    while (scanf("%d", &a), a)
    {
        s = getSort(a);
        printf("%d\n", s);
    }
    return 0;
}