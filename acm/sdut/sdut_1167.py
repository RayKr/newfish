'''
给出三个整数，请你设计一个程序，求出这三个数的和、乘积和平均数。
如果要连续输入多个数字，则用map(int, input().split())强制类型转换
'''


def func():
    a, b, c = map(int, input().split())
    print('%d %d %.2f' % (a+b+c, a*b*c, (a+b+c)/3))


func()
