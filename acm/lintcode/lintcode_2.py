'''
设计一个算法，计算出n阶乘中尾部零的个数
'''

'''
第一种方案：先求出阶乘，然后从后往前遍历，遇到第一个不为0的字符则输出尾数0的个数
'''


def first(n):
    f = str(factorial(n))
    print(f)
    zero = 0
    for i in range(len(f)-1, 0, -1):
        if f[i] == '0':
            zero += 1
        else:
            break
    print(zero)


def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)


'''
第二种方案：在阶乘中，每两个数相乘，如果出现尾数有0，则去掉0，并且记录出现的个数
这样就导致每次相乘的数，个位数永远不是0，那么除去个位数为0的情况，如果相乘还能得到0，只能是5
所以说，只需找到阶乘序列中，能被5整除的数的个数，就是尾数0的个数
'''


def second(n):
    # TODO 错误
    s = n // 5
    print(s)


def main():
    n = int(input())
    first(n)
    second(n)


main()
