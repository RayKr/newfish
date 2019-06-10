#include <stdio.h>

int main()
{
    int m, n, item, p = 0, q = 0;
    scanf("%d %d", &m, &n);
    int a[m], b[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &item);
        a[i] = item;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        b[i] = item;
    }

    while (p < m || q < n)
    {
        if (q >= n || a[p] < b[q])
        {
            printf("%d ", a[p]);
            p++;
        }
        else if (p >= m || a[p] > b[q])
        {
            printf("%d ", b[q]);
            q++;
        }
        else if (a[p] == b[q])
        {
            printf("%d %d ", a[p], b[q]);
            p++;
            q++;
        }
    }

    return 0;
}