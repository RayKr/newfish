'''
多行多数输入，遇到EOF停
'''


def foo():
    while True:
        try:
            a, b = map(int, input().split())
            print(a + b)
        except:
            break


foo()
