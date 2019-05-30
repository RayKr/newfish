'''
输入一个三位正整数，将它反向输出。
注意130逆置后是31
'''


def fuc():
    value = input()
    for i in range(len(value) - 1, -1, -1):
        if value[i] != '0':
            print(value[i], end='')
    print()


fuc()
