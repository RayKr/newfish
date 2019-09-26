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

2. 定义结构体
    * struct后紧跟着的LNode是结构体名称，大括号后面的LNode,*LinkList是用该结构体定义的数据类型。
    * 定义链表时的指针定义应该用 `struct LNode *next`，不要忘记struct。

3. `NULL`一定是用全部大写的。

4. 逗号表达式和逗号运算。先求解表达式1，再求解表达式2。整个逗号表达式的值是表达式2的值。

5. 字符串相关的操作：
```c
// string头文件
#include <string.h>

// 由于C中没有string类型，所以是用char[]来表示字符串

// 字符串做形参时,可以用指针
int freqs(char *source, char *destination) {}

// 获取字符串长度
int len = strlen(source);

// 截取字符串中的部分，类似java中的substring()，c中没有截取字符串的方法，而是用strncpy来替代实现
// strncpy(dest, src, n)方法是从src中复制n个字符到dest中
// 其中，要求dest必须是已初始化的数组
char dest[1000] = {""};
// 但是，实际应用中，可能只有当运行时才会确定数组大小，就需要动态初始化。
// 注意，c中不能直接用char dest[desLen]这样的方法来动态初始化，而必须使用malloc来动态申请内存空间
char* const dest = (char *)malloc(size(char) * n);
// 其中const修饰符在星号之后，则表示指针在被声明后不能改变，即只能指向这个获取的空间，完全符合数组的性质

// 两个字符串比较
int p = strcmp(str1, str2)
// 返回值是个int型，当p=0时，str1==str2;当p<0时，str1<str2;当p>0时；str1>str2
```

6. `''`里只能是一个字符，`""`里可以是多个字符组成的字符串。所以当表示字符串时，必须用双引号。

7. 符号常量和变量的区别。符号常量用 `#define PI 3.14`这样定义，符号常量不占内存，在预处理时就把程序里的符号替换。

8. C语言中的真和假用1和0来表示。

9. c语言也是严格区分大小写的。

10. `unsigned` 只能修饰整型，并且只能赋正值，使用`%u`输出。

11. 字符型可以直接和整型相加，字符型按ASCII码来与整型相加得到整型结果。 12 + 'A' = 77

12. 