
def first():
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    for i in range(len(a)):
        if len(b) == 0 or not checkIn(b, a[i]):
            b.append(a[i])
        i += 1
    print(len(b))
    for i in range(len(b)):
        print(b[i], end=' ')
    print()


def checkIn(b, item):
    for i in range(len(b)):
        if b[i] == item:
            return True
    return False


first()
