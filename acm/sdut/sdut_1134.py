'''
输出对n个数完成求和运算后的结果。
比如a=3，n=6时，s=3+33+333+3333+33333+333333
'''


def sum1(a, n):
    if n == 1:
        return a
    else:
        return sum(a, n - 1) + calNum(a, n)


def calNum(a, n):
    s = a
    for i in range(1, n):
        s += a * 10 ** (i)
    return s


def sum2(a, n):
    '''
    s = 3+33+333+3333+33333+333333 
      = 6 * 3 + 5 * 33 + 4 * 333 + 3 * 3333 + 2 * 33333 + 1 * 333333
      = Sum((n-i) * a * 10 ** i)
    '''
    s = 0
    for i in range(n):
        s += (n - i) * a * 10 ** i
    return s


def func():
    while True:
        try:
            a = int(input())
            n = int(input())
        except:
            break
    # print(sum1(a, n))
    print(sum2(a, n))


func()
