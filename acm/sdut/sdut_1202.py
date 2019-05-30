'''
判断一个数n能否同时被3和5整除。
输入一个正整数n。
如果能够同时被3和5整除，输出Yes，否则输出No。
'''


def func():
    n = int(input())
    if n % 3 == 0 and n % 5 == 0:
        print('Yes')
    else:
        print('No')


func()
