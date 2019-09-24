#include <stdio.h>
#include <stdlib.h>

// 线性表结构
#define InitSize 100
#define ElemType int
typedef struct
{
    ElemType *data;
    int MaxSize, length;
} SeqList;

// 初始化线性表
void InitList(SeqList *L)
{
    L->data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L->MaxSize = InitSize;
    L->length = 0;
    return 0;
}

/**
 * 求表长
 */
int Length(SeqList *L)
{
    return L->length;
}

/**
 * 插入操作 
 * 时间复杂度：O(n)
 * i 是序号，注意和下标的区分
 */
int ListInsert(SeqList *L, int i, ElemType e)
{
    // 判断i的范围是否有效
    if (i < 1 || i > L->length + 1)
    {
        return 0;
    }
    // 表已满
    if (L->length >= L->MaxSize)
    {
        return 0;
    }
    // 把i个元素及后面的元素后移，应该从后往前依次后移
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    // 在位置i处放入e
    L->data[i - 1] = e;
    // 长度+1
    L->length++;

    return 1;
}

/**
 * 删除操作 
 * 时间复杂度：O(n)
 * i 是序号，注意和下标的区分
 */
int ListDelete(SeqList *L, int i, ElemType e)
{
    // 判断i的范围是否有效
    if (i < 1 || i > L->length)
    {
        return 0;
    }
    // 表已空
    if (L->length == 0)
    {
        return 0;
    }
    // 先将要删除的元素赋值给e
    e = L->data[i - 1];
    // i后的每个元素前移，相当于删除该元素
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    // 长度-1
    L->length--;
    return 1;
}

int main()
{
    return 0;
}