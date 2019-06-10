#include <stdio.h>
#include <stdlib.h>
// 先定义线性表结构
#define LIST_INIT_SIZE 10000 //线性表存储空间的初始分配量
typedef int ElemType;        // 数据元素类型，int型
typedef struct
{
    ElemType *elem; // 基地址
    int length;     //线性表长度
    int listsize;   //分配的容量
} SqList;

// 定义线性表的操作
// 1. 初始化线性表
int InitList(SqList *L)
{
    //开辟一个存储空间，并把这块存储空间的基地址赋值给elem
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)
        return -1; //空间分配失败
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return 0;
}

// 2. 插入
int InsertIntoList(SqList *L, ElemType e)
{
    // 判断存储空间是否够用
    if (L->length >= L->listsize)
        return -1;

    // 尾插法
    L->elem[L->length] = e;
    // 长度+1
    ++L->length;
    return 0;
}

// 3. 查找当前元素前面是否已存在相同元素
int IsExist(SqList *L, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (L->elem[i] == L->elem[index])
        {
            return 1;
        }
    }

    return 0;
}

// 4. 删除
int DeleteFromList(SqList *L, int index)
{
    //判断删除位置的合法性
    if (index < 1 || index > L->length)
        return -1;
    // 删除当前元素, 当前位置后面所有元素依次前移位置
    ElemType *p, *q;
    p = &(L->elem[index]);     // 开始位置
    q = &(L->elem[L->length]); // 结束位置
    for (++p; p <= q; p++)
    {
        *(p - 1) = *p;
    }
    --L->length;
    return 0;
}

// 主函数
int main()
{
    int n, m, a;
    scanf("%d", &n);
    while (n--)
    {
        SqList list;
        InitList(&list);
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d", &a);
            // 插入顺序表
            InsertIntoList(&list, a);
        }
        // 从后往前遍历删除重复数据，并进行位置前移
        for (int i = list.length - 1; i >= 0; i--)
        {
            if (IsExist(&list, i))
            {
                DeleteFromList(&list, i);
            }
        }
        // 遍历输出纯表
        for (int i = 0; i < list.length; i++)
        {
            printf("%d ", list.elem[i]);
        }

        printf("\n");
    }

    return 0;
}