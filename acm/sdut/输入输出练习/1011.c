#include <stdio.h>

int main()
{
    int a, b, n;
    scanf("%d", &n);
    while (n-- != 0)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}