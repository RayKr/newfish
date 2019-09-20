#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *base;
    int *top;
    int n;
} Stack;

void init(Stack S)
{
    S.base = (int *)malloc(sizeof(int));
    S.top = S.base;
    S.n = 1;
}

void push(Stack S, char c)
{
    // 空间不足
    if (S.top - S.base == S.n)
    {
        
        S.base = (int *)realloc(S.base, (S.n + 1) * sizeof(int));
        S.top = S.base + S.n;
        S.n += 1;
        printf("%d %d %d", *S.base, *S.top, S.n);
    }
    // 压入栈
    *S.top = c;
    // 指针上移
    S.top++;
}

char pop(Stack S)
{
    --S.top;
    return *S.top;
}

int top(Stack S)
{
    char c = *--S.top;
    S.top++;
    return c;
}

int empty(Stack S)
{
    return S.base == S.top;
}

int check(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int canpush(char c, char top)
{
    printf("c=%c,top=%c\n", c, top);
    return c == '(' || c == ')' || top == '(' || ((top == '+' || top == '-') && (c == '*' || c == '/'));
}

void foo(Stack S, char c)
{
    if (empty(S) || canpush(c, top(S))) // 如果栈为空，或符号优先级大于栈顶，则入栈
    {
        push(S, c);
        printf("把%c放入栈\n", c);
    }
    else
    {
        if (top(S) == ')')
        {
            printf("aaaaaaaaaaa");
            while (top(S) != '(')
            {
                char c = pop(S);
                if (c != '(' && c != ')')
                    printf("%c", c);
            }
            // 弹出(
            pop(S);
        }
        else
        {
            printf("fsfsdafs");
            char c = pop(S);
            if (c != '(' && c != ')')
            {
                printf("%c", c);
            }
            foo(S, c);
        }
    }
}

int main()
{

    char *str = "a*b+(c-d/e)*f#";
    Stack S;
    init(S);
    for (int i = 0; str[i] != '#'; i++)
    {
        if (check(str[i])) // 如果是符号
        {
            foo(S, str[i]);
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}