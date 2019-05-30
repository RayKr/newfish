'''
线性表（顺序表、链表）

链表又有单链表、双向链表
'''


class List:
    '''
    顺序表
    '''

    def __init__(self):
        self.list = []

    def __str__(self):
        return str(self.list)

    def put(self, item):
        self.list.append(item)

    def size(self):
        return len(self.list)

    def isEmpty(self):
        return self.list == []


class LinkedList:
    '''
    单链表
    '''

    # 定义结点 内部类
    class __Node:
        item = None
        next = None

        def __init__(self, item, n):
            self.item = item
            self.next = n

    def __init__(self):
        self.__head = self.__Node(None, None)
        self.__size = 0

    # 按照顺序依次打印出来
    def __str__(self):
        # 默认头结点的下个结点
        p = self.__head.next
        l = []
        while p:
            # 打印当前结点
            l.append(p.item)
            # 指向下个结点
            p = p.next
        return str(l)

    # 头插法
    def put(self, item):
        # 新结点的next指向第一个结点
        node = self.__Node(item, self.__head.next)
        # 头结点指向该结点
        self.__head.next = node
        # size+1
        self.__size += 1

    # 删除第一个结点
    def remove(self):
        # 获取头结点后的第一个结点
        node = self.__head.next
        # 将头结点指向第二个结点（该结点的后一个结点）
        self.__head.next = node.next
        # size-1
        self.__size -= 1
        # 删除该结点删除的是对对象对引用，并没有真正删除数据
        del node

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0


class DoubleLoopLinked:
    '''
    双向循环链表

    在删除尾部结点时，我们需要将rear移动到其前一个结点，
    为了能直接访问到前一个结点，我们可以增加last字段指向前一个结点。
    '''

    class __Node:
        item = None
        next = None  # 指向该结点都下一个结点
        last = None  # 指向该结点都上一个结点

        def __init__(self, item, next, last):
            self.item = item
            self.next = next
            self.last = last

    def __init__(self):
        self.__head = self.__Node(None, None, None)
        self.__size = 0

    def __str__(self):
        p = self.__head.next
        l = []
        while p != self.__head:
            l.append(p.item)
            p = p.next
        return str(l)

    # 双向链表尾插法
    def insertToTail(self, item):
        if self.isEmpty():  # 如果链为空，则直接插入到头结点的后边，并且头尾指针都指向该结点
            # 创建一个新结点，指明让该结点都next和last指向谁
            node = self.__Node(item, self.__head, self.__head)
            # 指明头结点都next和last指向谁
            self.__head.next = node
            self.__head.last = node
        else:
            # 链不为空，则新结点都指针next指向头结点，last指向上一个尾结点
            node = self.__Node(item, self.__head, self.__head.last)
            # 上一个尾结点的next指向它
            self.__head.last.next = node
            # 头结点的last指向它
            self.__head.last = node
        self.__size += 1

    # 双向链表头插法
    def insertToHead(self, item):
        if self.isEmpty():  # 链表为空的时候和尾插法一样
            node = self.__Node(item, self.__head, self.__head)
            self.__head.next = node
            self.__head.last = node
        else:
            # 新结点的next指向下一个结点，last指向头结点
            node = self.__Node(item, self.__head.next, self.__head)
            # 下一个结点的last指向它
            self.__head.next.last = node
            # 头结点的next指向它
            self.__head.next = node
        self.__size += 1

    # 尾删除
    def removeTail(self):
        # 获取要删除的结点
        node = self.__head.last
        # 头结点的last指向新尾结点
        self.__head.last = node.last
        # 新尾结点的next指向头结点
        node.last.next = self.__head
        # size-1
        self.__size -= 1
        # 删除该结点引用
        del node

    # 头删除
    def removeHead(self):
        node = self.__head.next
        node.next.last = node.last
        node.last.next = node.next
        self.__size -= 1
        del node

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0


# 测试
# l = List()
# for i in range(10):
#     l.put(i)
# print(l.size())
# print(l)

# ll = LinkedList()
# for i in range(10):
#     ll.put(i)
# print(ll.size(), ll)
# ll.remove()
# print(ll.size(), ll)

dll = DoubleLoopLinked()
dll.insertToHead(1)
dll.insertToHead(2)
dll.insertToHead(3)
dll.insertToTail(4)
dll.insertToTail(5)
print(dll.size(), dll)
dll.removeHead()
dll.removeTail()
print(dll.size(), dll)
