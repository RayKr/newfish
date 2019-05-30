'''
从键盘输入两个时间点(24小时制），输出两个时间点之间的时间间隔，时间间隔用“小时:分钟:秒”表示。
如：3点5分25秒应表示为--03：05：25.假设两个时间在同一天内，时间先后顺序与输入无关。
'''


def func():
    while True:
        try:
            time1 = input().split(':')
            time2 = input().split(':')
        except:
            break
    # covnert to secs
    secs1 = int(time1[0]) * 3600 + int(time1[1]) * 60 + int(time1[2])
    secs2 = int(time2[0]) * 3600 + int(time2[1]) * 60 + int(time2[2])
    # sub
    sub = abs(secs2 - secs1)
    # covert to time format
    hh = sub // 3600
    mm = (sub % 3600) // 60
    ss = sub % 60
    print(convertInt2String(hh) + ':' +
          convertInt2String(mm) + ':' + convertInt2String(ss))


def convertInt2String(i):
    if i < 10:
        return '0' + str(i)
    else:
        return str(i)


func()
