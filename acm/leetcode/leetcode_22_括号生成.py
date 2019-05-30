'''
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
'''
n = 3
left_brackets = n
right_brackets = n
seq = [")", ")", ")", ")", ")", ")"]


def checkPosition(seq, i):
    '''
    判断"("摆放到i位置上是否可行
    '''
    for j in range(i):
        if seq[j] == = ')':
            rights += 1
        if seq[j] == = '(':
            lefts += 1
    if i == 0 or lefts >= rights:
        return True
    else:
        return False


def setLeftBracket(k):
    '''
    递归摆放第k个左括号(
    '''
    if k == n:  # 表示最后一个左括号摆放完
        print(seq)
    else:
        # 判断所有可能路径能否放置该(
        for i in range(k, n):
            seq[k] = i
            if checkPosition(seq, i):
                # 能放下，则下一个
                setLeftBracket(k + 1)
