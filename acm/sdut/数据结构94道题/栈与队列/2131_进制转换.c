#include <stdio.h>
#include <math.h>

int rst;

int cal(int a, int R, int level)
{
    int c = a / R; // 除数
    int y = a % R; // 余数
    rst += y * pow(10, level);

    if (c >= R)
    {
        level++;
        cal(c, R, level);
    }
    else
    {
        rst += c * pow(10, level + 1);
    }

    return 0;
}

int main()
{
    int a, R;
    scanf("%d", &a);
    scanf("%d", &R);
    cal(a, R, 0);
    printf("%d", rst);

    return 0;
}