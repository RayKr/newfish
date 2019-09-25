## C与C++语法上需要注意的点

1. C没有引用类型，C++有引用类型。
```c
// C用指针来实现引用类型，并且用->来表示.
int get(SeqList *L) {
    return L->length;
}
```
```c++
// C++引用类型&L，可以直接用.
int get(SeqList &L) {
    return L.length;
}
```

