#include <stdio.h>

void backwards(int b[], int start, int end)
{
    for (int i = start; i < (end + start) / 2; i++)
    {
        // 交换位置
        int temp = b[end - 1 + start - i];
        b[end - 1 + start - i] = b[i];
        b[i] = temp;
    }
}

int main()
{
    int n, len, m, a;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &len, &m);
        int b[len];
        for (int i = 0; i < len; i++)
        {
            scanf("%d", &a);
            b[i] = a;
        }
        backwards(b, 0, m);
        backwards(b, m, len);
        backwards(b, 0, len);
        // 输出
        for (int i = 0; i < len; i++)
        {
            printf("%d ", b[i]);
        }
        printf("\n");
    }

    return 0;
}