#include <stdio.h>
#include <stdlib.h>

#define ElemType int
typedef struct LNode
{
    ElemType data;
    // 记住 struct LNode *next
    struct LNode *next;
} LNode, *LinkList;
// struct后紧跟着的LNode是结构体名称，大括号后面的LNode,*LinkList是用该结构体定义的数据类型

// 初始化链表
// 因为LinkList是定义的指针类型，所以L已经是个指针类型，不能再加*L
int InitLinkList(LinkList L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return 1;
}

// 头插法
// 时间复杂度：O(n)
int List_HeadInsert(LinkList L, ElemType e)
{
    LNode *n;
    n->data = e;       // 赋值
    n->next = L->next; // 当前结点的next指向头结点的next
    L->next = n;       // 头结点的next再指向当前结点
    // 注意上述两个顺序一定不能乱，一定要先操作当前指针的next，再将头结点的next指向该结点
    return 1;
}

// 尾插法
// 时间复杂度：O(n)
int List_TailInsert(LinkList L, ElemType e)
{
    // 先找到尾结点
    
}

int main()
{
    return 0;
}