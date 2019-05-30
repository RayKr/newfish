#include <stdio.h>

int main()
{
    int a, b;
    // 逗号表达式，从左到右，最终结果为最后一个表达式结果
    // a || b 等同于 !(a==0&&b==0)，即当a、b同时为0时退出循环
    while (scanf("%d %d", &a, &b), a || b)
    {
        printf("%d\n", a + b);
    }

    return 0;
}