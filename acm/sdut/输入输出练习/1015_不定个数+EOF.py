def foo():
    while True:
        try:
            l = list(map(int, input().split()))
            s = 0
            for i in range(1, l[0]+1):
                s += l[i]
            print(s)
        except:
            break


foo()
