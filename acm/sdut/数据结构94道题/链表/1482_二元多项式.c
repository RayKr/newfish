#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    ElemType x;
    ElemType y;
    struct Node *prev;
    struct Node *next;
} Node;

Node *List;

Node *initCycleNode()
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = n;
    n->prev = n;
    n->data = 1;
    n->x = 0;
    n->y = 0;
    return n;
}

Node *initNode()
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = NULL;
    n->prev = NULL;
    n->data = 1;
    n->x = 0;
    n->y = 0;
    return n;
}

// 按格式输出
void printList(Node *Head)
{
    Node *cur = Head->next;
    while (cur != NULL && cur != Head)
    {
        if ((cur->x == 0 && cur->y == 0) || cur->data != 1)
        {
            printf("%d", cur->data);
        }
        if (cur->x != 0)
        {
            printf("x");
        }
        if (cur->x > 1)
        {
            printf("^%d", cur->x);
        }
        if (cur->y != 0)
        {
            printf("y");
        }
        if (cur->y > 1)
        {
            printf("^%d", cur->y);
        }

        if (cur->next != NULL && cur->next != Head)
        {
            printf("+");
        }

        cur = cur->next;
    }
    printf("\n");
}

// 创建每行的链
int createList(Node *L, char *s)
{
    Node *tail = L;
    Node *node = initNode();
    int len = strlen(s);
    for (int i = 0; i <= len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9') // 遇到系数
        {
            char xs[1000] = {""};
            int j = i;
            while (s[i] != '+' && i != len && s[i] >= '0' && s[i] <= '9') // 循环直到遇到+或结束，且为整数,来获取x的幂
            {
                i++;
            }
            strncpy(xs, &s[j], i - j);
            i--;
            node->data = atoi(xs);
        }
        else if (s[i] == 'x') // 遇到x
        {
            if (i + 1 < len && s[i + 1] == '^') // 下一个字符是否为^
            {
                i += 2;
                char xm[1000] = {""};
                int j = i;
                while (s[i] != '+' && i != len && s[i] >= '0' && s[i] <= '9') // 循环直到遇到+或结束，且为整数,来获取x的幂
                {
                    i++;
                }
                strncpy(xm, &s[j], i - j);
                i--;
                node->x = atoi(xm);
            }
            else
            {
                node->x = 1;
            }
        }
        else if (s[i] == 'y') // 遇到y
        {
            if (i + 1 < len && s[i + 1] == '^') // 下一个字符是否为^
            {
                i += 2;
                char ym[1000] = {""};
                int j = i;
                while (s[i] != '+' && i != len && s[i] >= '0' && s[i] <= '9') // 循环直到遇到+或结束，且为整数,来获取x的幂
                {
                    i++;
                }
                strncpy(ym, &s[j], i - j);
                i--;
                node->y = atoi(ym);
            }
            else
            {
                node->y = 1;
            }
        }
        else if (s[i] == '+' || i == len) // 遇到+或结束，追加结点
        {
            // 将node串到L上
            node->prev = tail;
            tail->next = node;
            tail = node;
            // 创建新结点
            node = initNode();
        }
    }
    tail->next = L;
    L->prev = tail;
    return 0;
}

// 判断大小
int isbiger(Node *p, Node *q)
{
    int flag = 0;

    if (p->x > q->x)
    {
        return 1;
    }
    else if (p->x == q->x)
    {
        if (p->y != 0 && q->y != 0)
        {
            return p->y > q->y;
        }
        if (p->x != 0)
        {
            if (p->y == 0)
            {
                return 1;
            }
            else if (q->y == 0)
            {
                return 0;
            }
            else
            {
                return p->y > q->y;
            }
        }
        else
        {
            if (p->y == 0 && q->y == 0)
            {
                return p->data > q->data;
            }
            else
            {
                return p->y > q->y;
            }
        }
    }
    else
    {
        return 0;
    }

    return 0;
}

// 排序
int sort()
{
    Node *p = List->next->next; // p用来遍历每个Node
    Node *inst, *temp;          // 插入位置
    while (p != List)
    {
        inst = List->next;
        while (inst != p)
        {
            if (isbiger(p, inst))
            {
                temp = p;
                // 先删掉p
                p->next->prev = p->prev;
                p->prev->next = p->next;
                // 在inst前插入结点
                inst->prev->next = temp;
                temp->prev = inst->prev;
                temp->next = inst;
                inst->prev = temp;
                // p往前移1
                p = p->prev;
                break;
            }
            inst = inst->next;
        }
        p = p->next;
    }

    return 0;
}

// 合并同类项
int merge()
{
    Node *p = List->next, *q, *temp;
    while (p != List)
    {
        q = p->next;
        while (q != List)
        {
            if (p->x == q->x && p->y == q->y)
            {
                // 合并系数
                p->data = p->data + q->data;
                // 删除q结点
                temp = q;
                q->next->prev = q->prev;
                q->prev->next = q->next;
                q = q->prev;
                free(temp);
            }

            q = q->next;
        }

        p = p->next;
    }
    return 0;
}

// 加法
int listPlus(Node *L)
{
    // 合并链
    List->prev->next = L->next;
    L->next->prev = List->prev;
    List->prev = L->prev;
    L->prev->next = List;

    return 0;
}

// 乘法
int listMulti(Node *L)
{

    return 0;
}

int main()
{
    int n;
    char oper;
    char s[1000];
    scanf("%d %s", &n, &oper);
    List = initCycleNode();
    Node *L = (Node *)malloc(sizeof(Node));
    while (scanf("%s", s), s[0] != '0')
    {
        createList(L, s);
        if (oper == '+')
        {
            listPlus(L);
            merge();
        }
    }
    // 排序
    sort();
    // 按格式打印
    printList(List);

    return 0;
}
