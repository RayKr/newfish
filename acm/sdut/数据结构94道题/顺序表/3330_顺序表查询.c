#include <stdio.h>

// 有序的顺序表查找用折半查找算法
int halfSearch(int a[], int p, int start, int end)
{
    int half = (end + start) / 2;
    if (a[half] == p)
    {
        return half + 1;
    }
    if (start >= end)
    {
        return -1;
    }
    else if (p > a[half])
    {
        return halfSearch(a, p, half + 1, end);
    }
    else if (p < a[half])
    {
        return halfSearch(a, p, start, half - 1);
    }
    return -1;
}

int main()
{
    int m, n, item, p = 0, q = 0;
    scanf("%d", &m);
    int a[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &item);
        a[i] = item;
    }
    scanf("%d", &n);
    int b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        b[i] = item;
    }

    for (int i = 0; i < n; i++)
    {
        int index = halfSearch(a, b[i], 0, m - 1);
        if (index == -1)
        {
            printf("No Found!\n");
        }
        else
        {
            printf("%d\n", index);
        }
    }

    return 0;
}
