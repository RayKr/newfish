'''
小瑜是个爱吃糖果的馋鬼，天天嚷着要爸爸买糖果，可是爸爸很忙，哪有时间啊，于是就让小瑜自己去了，
糖果3角钱一块，爸爸给小瑜n元钱，请你告诉小瑜最多能买几块糖，还剩几角钱？
单位为角
'''

unit_price = 3


def func():
    sum = int(input()) * 10
    print('%d %d' % (sum // unit_price, sum % unit_price))


func()
