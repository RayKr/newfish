#include <stdio.h>
#include <stdlib.h>

// 线性表结构
#define InitSize 100
#define ElemType int
typedef struct
{
    ElemType *data;
    int MaxSize, lenght;
} SeqList;

void InitList(SeqList &L)
{
    L.data = new ElemType(InitSize);
}

int main()
{
    return 0;
}