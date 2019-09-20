#include <stdio.h>

int main()
{
    int n, a, i = 0, even, start, end;
    int max, min;
    float center;
    int centerInt;
    scanf("%d", &n);
    // 判断总数奇偶性，关系到中位数的计算
    if (n % 2 == 0)
    {
        even = 1;
        start = n / 2 - 1;
    }
    end = n / 2;

    while (n--)
    {
        scanf("%d", &a);
        // 判断最值
        if (i == 0)
        {
            max = a;
            min = a;
        }
        else
        {
            if (max < a)
            {
                max = a;
            }
            if (min > a)
            {
                min = a;
            }
        }
        // 判断中位数
        if (even == 1)
        {
            if (i == start || i == end)
            {
                center += a;
                centerInt += a % 2;
            }
        }
        else
        {
            if (i == end)
            {
                center = a;
            }
        }
        i++;
    }

    if (centerInt == 1 && even == 1)
    {
        printf("%d %.1f %d", max, center / 2, min);
    }
    else
    {
        printf("%d %.0f %d", max, center, min);
    }

    return 0;
}