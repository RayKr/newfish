# 第20章 矩阵相乘
# 动态规划法 O(n^3)

N = 100


def cmm(n, seq):  # n矩阵数，seq是维数序列
    cost = [[0]*N for i in range(N)]
    trace = [[0]*N for i in range(N)]

    for p in range(1, n):
        for i in range(n - p):
            j = i + p
            tempCost = -1
            for k in range(i, j):
                temp = cost[i][k] + cost[k + 1][j] + \
                    seq[i] * seq[k+1] * seq[j+1]
                if tempCost == -1 or tempCost > temp:
                    tempCost = temp
                    tempTrace = k
                    print(temp, tempCost)
            cost[i][j] = tempCost
            trace[i][j] = tempTrace

    return cost[0][n-1]


mx = cmm(5, [5, 10, 3, 12, 5, 50, 6])
print(mx)
