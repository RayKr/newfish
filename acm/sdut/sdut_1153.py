'''
输入两个整数，请编程求其中的较大者。
'''


def getMax():
    a, b = map(int, input().split())
    print('max=%d' % max(a, b))


getMax()
