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
    Node *tail = L; // 指向当前尾结点的指针
    // 依次输入并创建链表
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        // 尾插法保证按插入顺序记录
        Node *c = (Node *)malloc(sizeof(Node)); // 申请空间
        c->data = a;                            // 赋值
        c->next = NULL;                         // 新结点的next指针指向NULL
        tail->next = c;                         // 尾结点的next指向该结点
        tail = c;                               // 当前结点变成新的尾结点
    }

    // 要删除的数据
    scanf("%d", &d);
    printf("%d\n", getLinkedListLength(L));
    printLinkedList(L);
    Node *cur = L;
    while (cur->next != NULL)
    {
        if (d == cur->next->data)
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