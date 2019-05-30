'''
4 1 2 3 3
5 1 2 4 4 5
0
每一行的输入是不定个数，并且第一个数是个数
其中， 4是求和的个数，1+2+3+3=9
遇到0退出
9
16
'''


def foo():
    while True:
        l = list(map(int, input().split()))
        if (len(l) == 1 and l[0] == 0):
            break
        s = 0
        for i in range(1, l[0]+1):
            s += l[i]
        print(s)


foo()
