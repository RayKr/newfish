'''
先输入行数
再依次输入多组数
输入N行后自动结束，不是遇到EOF结束
'''


def foo():
    n = int(input())
    for i in range(n):
        a, b = map(int, input().split())
        print(a + b)


foo()
