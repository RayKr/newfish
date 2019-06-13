#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

int fs;
char s[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int headInsert(Node *l, ElemType e)
{
    // 头插法
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = e == '-' ? '-' : s[e];
    n->next = l->next;
    l->next = n;
    return 0;
}

int printList(Node *l)
{
    Node *tail = l->next;
    while (tail)
    {
        printf("%c", tail->data);
        tail = tail->next;
    }
    printf("\n");
    return 0;
}

int cal(Node *l, int a, int R)
{
    // 考虑负数
    if (a < 0)
    {
        a = -a;
        fs = 1;
    }

    // 考虑 a < R 的情况
    if (a < R)
    {
        headInsert(l, a);
        // 符号
        if (fs)
            headInsert(l, '-');
    }
    else
    {
        int c = a / R;
        int y = a % R;
        headInsert(l, y);
        cal(l, c, R);
    }

    return 0;
}

int main()
{
    int a, R;
    while (scanf("%d %d", &a, &R) != EOF)
    {
        Node *l = (Node *)malloc(sizeof(Node));
        l->next = NULL;
        fs = 0;
        cal(l, a, R);
        printList(l);
        free(l);
    }

    return 0;
}