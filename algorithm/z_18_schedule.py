# 第18章 m台机器运行n个任务，求完成所有任务所需要到时间最短
# 贪心算法 O(mn)


def schedule():
    m = 3
    n = 7
    t = [16, 14, 6, 5, 4, 3, 2]

    s = [[0] for i in range(m)]   # s[i][j]表示机器i运行的任务j的编号
    d = [0 for i in range(m)]   # 当前每个机器正在运行的任务时长
    count = [0 for i in range(m)]   # 每个机器运行的任务个数

    # 分配前 m 个任务，把任务下标添加到二维数组s中去
    for i in range(m):
        s[i][0] = i
        d[i] = t[i]
        count[i] = 1
    print(s, d, count)

    # 分配后 n-m 个任务
    for i in range(m, n):
        min = d[0]
        k = 0
        # 选出一个最小运行时间任务
        for j in range(m):
            if (min > d[j]):
                min = d[j]
                k = j
        # 把任务编号排到机器任务列表里
        # C语言 s[k][count[k]] = i
        s[k].append(i)
        count[k] += 1
        d[k] += t[i]
        print(s, d, count)

    # 获取完成所有任务需要的时间，即每个机器的任务完成时间中的最大值
    mx = max(d)
    print(mx)


schedule()
