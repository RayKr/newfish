#include <stdio.h>

int main()
{
    int t, n;
    double s;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        s = 0.0;
        n = n > 1000 ? 1000 : n;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                s -= 1.0 / i;
            }
            else
            {
                s += 1.0 / i;
            }
        }
        printf("%.2f\n", s);
    }

    return 0;
}