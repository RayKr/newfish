#include <stdio.h>

int check(int b[], int max, int item)
{
    for (int i = 0; i < max; i++)
    {
        if (b[i] == item)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, item, a[1000], b[1000], max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        // a[i] = item;
        if (check(b, max, item))
        {
            b[max] = item;
            max++;
        }
    }
    printf("%d\n", max);
    for (int i = 0; i < max; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}