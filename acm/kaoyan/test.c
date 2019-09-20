#include <stdio.h>

int main()
{
    int n, a, b, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        if (i == 0)
        {
            x = a;
            y = b;
        }
        else
        {
            if (a < x)
            {
                x = a;
                y = b;
            }
            else if (a == x)
            {
                if (b < y)
                {
                    y = b;
                }
            }
        }
    }
    printf("%d %d", x, y);
    return 0;
}