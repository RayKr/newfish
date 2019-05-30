#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10000 //线性表存储空间的初始分配量
typedef int ElemType;        // 数据元素类型，int型
typedef struct
{
    ElemType *elem; // 基地址
    int length;     //线性表长度
    int listsize;   //分配的容量
} SqList;

int IsExist(SqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->elem[i] == e)
        {
            return 1;
        }
    }
    return 0;
}

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

// 建表删除，其实就是边建边删，先判断当前数据是否重复，如果重复则不插入
int InsertIntoList(SqList *L, ElemType e)
{
    // 判断存储空间是否够用
    if (L->length >= L->listsize)
        return -1;
    // 判断是否重复
    if (!IsExist(L, e))
    {
        // 尾插法
        L->elem[L->length] = e;
        // 长度+1
        ++L->length;
        // 接着打印输出
        printf("%d ", e);
    }
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
            InsertIntoList(&list, a);
        }
        printf("\n");
    }

    return 0;
}