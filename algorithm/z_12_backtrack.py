# 第12章 回溯法
'''
从m个供应商采购n个部件，供应商j供应的i部件具有重量Wij和价格Cij
求解总价不超过cc的最小重量的机器组成
'''

n = 3  # 部件数
m = 3  # 供应商数
cc = 4  # 总价值上限
w = [[1, 2, 3], [3, 2, 1], [2, 2, 2]]  # 供应商、部件、重量对应关系
c = [[1, 2, 3], [3, 2, 1], [2, 2, 2]]  # 供应商、部件、价格对应关系
bestW = 8   # 当前解最小重量
bestC = 0  # 当前解最小重量的机器价格
bestX = [0, 0, 0]  # 最优解，一维数组，bestX[i]代表第i个部件来自哪个供应商
cw = 0  # 搜索过程中机器的重量
cp = 0  # 搜索过程中机器的价格
x = [0, 0, 0]  # 搜索过程中产生的解，x[i]标识第i个部件来自哪个供应商


def backtrack(i):   # i为当前部件，0<=i<n
    found = 0  # 发现标志
    # 得到问题的解
    if i > n-1:
        bestW = cw
        bestC = cp
        for j in range(n):
            bestX[j] = x[j]  # bestX.append(x[j])
        return 1
    # 有解
    if cp < cc:
        found = 1
    for j in range(m):
        # i个部件由j来供应
        x[i] = j
        cw += w[i][j]
        cp += c[i][j]
        # 满足当价格没超上限，重量比最小重量小这两个条件，才去考虑往深一层拓展，不然根本不考虑，直接回溯
        if (cp <= cc and cw <= bestW):
            if backtrack(i + 1):
                found = 1
        else:
            # 回溯
            cw -= w[i][j]
            cp -= c[i][j]
    return found


backtrack(0)
