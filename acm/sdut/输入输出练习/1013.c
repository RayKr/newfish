#include <stdio.h>

int main()
{
    int a, b, n, s;
    // 每一行第一个输入的数为后边的个数
    while (scanf("%d", &n), n)
    {
        s = 0;
        // 后续在这一行中输入n个数
        while (n--)
        {
            scanf("%d", &a);
            s += a;
        }
        printf("%d\n", s);
    }

    return 0;
}