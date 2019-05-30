'''
多行多数输入，遇到0 0停
'''


def foo():
    while True:
        a, b = map(int, input().split())
        if (a == b == 0):
            break
        print(a + b)


foo()
