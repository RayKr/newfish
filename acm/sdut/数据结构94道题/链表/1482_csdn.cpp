#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Point
{
    int x;   //x的次幂
    int y;   //y的次幂
    int num; //多项式的系数
    Point *next;
} head[10];
char str[1100];
Point *Creat()
{
    Point *p;
    p = new Point;
    p->num = 0;
    p->x = 0;
    p->y = 0;
    p->next = NULL;
    return p;
}
void Build(Point *root)
{
    Point *p;
    int len, data, ans;
    p = Creat();
    len = strlen(str);
    data = 0;
    ans = 1;
    for (int i = len - 1; i >= 0; i--) //从后向前
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            data = (str[i] - '0') * ans + data;
            ans *= 10;
        }
        else if (str[i] == 'x')
        {
            if (data)
                p->x = data;
            else
                p->x = 1;
            data = 0;
            ans = 1;
        }
        else if (str[i] == 'y')
        {
            if (data)
                p->y = data;
            else
                p->y = 1;
            data = 0;
            ans = 1;
        }
        else if (str[i] == '+')
        {
            if (data)
            {
                p->num = data;
            }
            else if (p->x || p->y)
            {
                p->num = 1;
            }
            p->next = root->next;
            root->next = p;
            data = 0;
            ans = 1;
            p = Creat();
        }
    }
    if (data)
    {
        p->num = data;
    }
    else if (p->x || p->y)
    {
        p->num = 1;
    }
    p->next = root->next;
    root->next = p;
}

void Link(Point *Root, Point *root)
{
    Point *p, *q, *temp, *t;
    temp = Creat();
    p = Root->next; //模拟多项式的乘法
    while (p)
    {
        q = root->next;
        while (q)
        {
            t = Creat();
            t->num = p->num * q->num;
            t->x = p->x + q->x;
            t->y = p->y + q->y;
            t->next = temp->next;
            temp->next = t;
            q = q->next;
        }
        p = p->next;
    }
    Root->next = temp->next;
    free(temp);
}
void Sort(Point *root)
{
    Point *p, *q, *temp;
    p = root->next;
    while (p) //合并同类项
    {
        temp = p;
        q = p->next;
        while (q)
        {
            if (p->x == q->x && p->y == q->y && p->num)
            {
                p->num += q->num;
                temp->next = q->next;
                free(q);
                q = temp->next;
            }
            else if (p->num == 0 && q->num == 0)
            {
                p->x = 0;
                p->y = 0;
                temp->next = q->next;
                free(q);
                q = temp->next;
            }
            else
            {
                temp = temp->next;
                q = q->next;
            }
        }
        p = p->next;
    }
    p = root->next;
    while (p) //排序
    {
        q = p->next;
        while (q)
        {
            if (p->x < q->x)
            {
                swap(p->x, q->x);
                swap(p->num, q->num);
                swap(p->y, q->y);
            }
            else if (p->x == q->x && p->x)
            {
                if (q->y == 0 && p->y != 0)
                {
                    swap(p->x, q->x);
                    swap(p->num, q->num);
                    swap(p->y, q->y);
                }
                else if (p->y < q->y && p->y != 0)
                {
                    swap(p->x, q->x);
                    swap(p->num, q->num);
                    swap(p->y, q->y);
                }
            }
            else if (p->x == q->x && p->x == 0)
            {
                if (p->y < q->y)
                {
                    swap(p->x, q->x);
                    swap(p->num, q->num);
                    swap(p->y, q->y);
                }
            }
            q = q->next;
        }
        p = p->next;
    }
}
void Output(Point *root)
{
    Point *p;
    p = root->next;
    while (p)
    {
        if (p != root->next)
        {
            printf("+");
        }
        if (p->num)
        {
            if (p->num != 1 || (p->x == 0 && p->y == 0))
                printf("%d", p->num);
        }
        else
        {
            printf("0");
            p = p->next;
            continue;
        }
        if (p->x)
        {
            printf("x");
            if (p->x != 1)
                printf("^%d", p->x);
        }
        if (p->y)
        {
            printf("y");
            if (p->y != 1)
                printf("^%d", p->y);
        }
        p = p->next;
    }
    printf("\n");
}
int main()
{
    int n;
    char c[2];
    while (scanf("%d", &n), n)
    {
        scanf("%s", c);
        for (int i = 0; i <= n; i++)
        {
            head[i].next = NULL;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            Build(&head[i]);
        }
        if (c[0] == '+') //如果是加法进行连接，然后合并同类项，排序
        {
            Point *p;
            p = &head[0];
            for (int i = 1; i <= n; i++)
            {
                p->next = head[i].next;
                while (p->next)
                {
                    p = p->next;
                }
            }
        }
        else if (c[0] == '*') //如果是乘法，进行乘法，然后合并排序
        {
            head[0].next = head[1].next;
            for (int i = 2; i <= n; i++)
            {
                Link(&head[0], &head[i]);
            }
        }
        Sort(&head[0]);
        Output(&head[0]);
    }
    return 0;
}