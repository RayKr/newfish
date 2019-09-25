#include <stdio.h>
#include <stdlib.h>
// 字符串的方法得用到string.h头文件
#include <string.h>

int freqs(char *source, char *destination)
{
    int num = 0;
    int desLen = strlen(destination);
    int srcLen = strlen(source);
    // 如果字串长度大于源串，则直接返回0
    if (desLen > srcLen)
    {
        return 0;
    }
    // 遍历源串，逐个比较
    for (int i = 0; i <= srcLen - desLen; i++)
    {
        // 在使用strncpy时要注意dest的初始化问题
        // 两种初始化方法
        // 1.确定的数组大小 char dest[1000] = {""};
        // 2.不确定数组大小，只能等运行时才能确定的，用malloc来实现，注意跟Java不一样，不能直接用char dest[desLen]来初始化
        char* const dest = (char *)malloc(sizeof(char) * (desLen + 1));
        strncpy(dest, source + i, desLen);
        if (strcmp(dest, destination) == 0)
        {
            num++;
        }
    }
    return num;
}

int main()
{
    int times = freqs("abcdefgdefkdxef", "def");
    printf("%d\n", times);
    return 0;
}