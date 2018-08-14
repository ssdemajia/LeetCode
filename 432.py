#  https://leetcode-cn.com/problems/all-oone-data-structure/description/
class Node:
    def __init__(self, prev=None, nex=None, val=None):
        self.prev = prev
        self.next = nex
        self.val = val


class DoubleLinkList:
    def __init__(self):
        self.head = Node()
        self.head.next = self.head
        self.head.prev = self.head
        self.head.val = 0
        self.len = 0

    def __len__(self):
        return self.len

    def __str__(self):
        l = []
        count = 0
        p = self.head.next
        while count < len(self):
            l.append(str(p.val))
            p = p.next
            count += 1
        return "->".join(l)

    def add_at_head(self, val):
        # 将指定值放入链表
        node = Node(self.head, self.head.next, val)
        node.next.prev = node
        node.prev.next = node
        self.len += 1

    def add_at_tail(self, val):
        node = Node(self.head.prev, self.head, val)
        node.prev.next = node
        node.next.prev = node
        self.len += 1

    def add_at_index(self, index, val):
        """
        index从0开始，插入到index位置元素前面
        :param index:
        :param val:
        :return:
        """
        if index < 0 or index > self.len:
            raise IndexError('index错误')
        elif index == self.len:
            self.add_at_tail(val)
        elif index == 0:
            self.add_at_head(val)
        else:
            p = self.__get_index(index)
            node = Node(p.prev, p, val)
            node.prev.next = node
            node.next.prev = node
            self.len += 1

    def del_at_head(self):
        """
        删除链表头
        :return:
        """
        if self.len == 0:
            raise IndexError('链表为空')
        old_head = self.head
        self.head = self.head.next
        self.head.prev = old_head.prev
        self.head.prev.next = self.head
        del old_head
        self.len -= 1

    def del_at_tail(self):
        # 删除链表尾部
        if self.len == 0:
            raise IndexError('链表为空')
        old_tail = self.head.prev
        self.head.prev = old_tail.prev
        old_tail.prev.next = self.head
        del old_tail
        self.len -= 1

    def del_at_index(self, index):
        # 删除指定index元素
        if index < 0 or index >= self.len:
            raise IndexError('index超出链表范围')
        elif index == 0:
            self.del_at_head()
        elif index == self.len-1:
            self.del_at_tail()
        else:
            p = self.__get_index(index)
            p.next.prev = p.prev
            p.prev.next = p.next
            del p
        self.len -= 1

    def __get_index(self, index):
        # 内部方法，用来遍历到指定index
        count = 0
        p = self.head.next
        while count < index:
            p = p.next
            count += 1
        return p

    def get_at_index(self, index):
        # 得到指定index的内容
        if index < 0 or index >= self.len:
            raise IndexError('index超出链表范围')
        elif index == 0:
            return self.get_at_head()
        elif index == self.len-1:
            return self.get_at_tail()
        else:
            p = self.__get_index(index)
            return p

    def get_at_head(self):
        # 获得头部元素的值
        if self.len <= 0:
            raise IndexError('链表为空')
        return self.head.next

    def get_at_tail(self):
        # 获得尾部元素的值
        if self.len <= 0:
            raise IndexError('链表为空')
        return self.head.prev

    def del_by_node(self, node):
        """
        删除指定链表中node节点
        :param node:
        :return:
        """
        node.next.prev = node.prev
        node.prev.next = node.next
        del node
        self.len -= 1

    def add_by_node(self, node, val):
        """
        在当前node之前添加一个新的, node相当于迭代器
        :param val:
        :param node:
        :return:
        """
        n = Node(node.prev, node, val)
        n.prev.next = n
        n.next.prev = n
        self.len += 1
        return n


class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keys = {}
        self.count_key = DoubleLinkList()

    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        if key not in self.keys:
            if len(self.count_key) == 0:
                self.count_key.add_at_tail([1, {key}])
                self.keys[key] = self.count_key.get_at_tail()
            else:
                head = self.count_key.get_at_head()
                if head.val[0] > 1:
                    self.count_key.add_at_head([1, {key}])
                    self.keys[key] = self.count_key.get_at_head()
                else:
                    head.val[1].add(key)
                self.keys[key] = self.count_key.get_at_head()
        else:
            current = self.keys[key]
            if current == self.count_key.get_at_tail() or current.next.val[0] - current.val[0] > 1:
                node = self.count_key.add_by_node(current.next, [current.val[0]+1, {key}])
                self.keys[key] = node
            else:
                current.next.val[1].add(key)
                self.keys[key] = current.next
            current.val[1].remove(key)
            if len(current.val[1]) == 0:
                self.count_key.del_by_node(current)

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        if key not in self.keys:
            return
        current = self.keys[key]
        if current.val[0] == 1:
            self.keys.pop(key)
        elif current == self.count_key.get_at_head() or current.val[0] - current.prev.val[0] > 1:
            node = self.count_key.add_by_node(current, [current.val[0]-1, {key}])
            self.keys[key] = node
        else:
            current.prev.val[1].add(key)
            self.keys[key] = current.prev
        current.val[1].remove(key)
        if len(current.val[1]) == 0:
            self.count_key.del_by_node(current)

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if len(self.count_key) == 0:
            return ""
        key = self.count_key.get_at_tail().val[1].pop()
        self.count_key.get_at_tail().val[1].add(key)
        return key

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if len(self.count_key) == 0:
            return ""
        key = self.count_key.get_at_head().val[1].pop()
        self.count_key.get_at_head().val[1].add(key)
        return key
# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()


if __name__ == '__main__':
    lists = DoubleLinkList()
    lists.add_at_head(1)
    lists.add_at_tail(3)
    lists.add_at_index(1, 2)
    lists.add_at_index(3, 4)
    print(lists)
    lists.del_at_tail()
    print(lists)
    lists.del_at_index(1)
    print(lists)
    lists.del_at_head()
    lists.add_at_tail(10)
    lists.add_at_tail(20)
    print(lists)

    print(lists.get_at_tail().val)
    print(lists.get_at_head().val)
    print(lists.get_at_index(1).val)
    def test1():
        o = AllOne()
        o.inc('h')
        o.inc('g')
        o.inc('h')
        o.inc('h')
        print(o.getMaxKey())
        o.inc('l')
        o.inc('c')
        o.inc('l')
        o.dec('h')
        o.dec('h')
        o.dec('h')
        o.inc('l')
        o.inc('c')
        o.inc('c')
        print(o.getMaxKey())
        print(o.getMinKey())


    def test2():
        o = AllOne()
        o.inc('h')
        o.inc('g')
        o.inc('h')
        o.inc('h')
        o.inc('l')
        o.inc('c')
        o.inc('l')
        o.dec('h')
        o.inc('l')
        o.inc('c')
        o.inc('c')
        print(o.getMaxKey())

    def test3():
        o = AllOne()
        o.inc('h')
        o.inc('h')
        o.inc('h')
        o.inc('w')
        o.inc('w')
        o.dec('w')
        assert o.getMaxKey() == 'h'
        assert o.getMinKey() == 'w'

    test1()
    test2()
    test3()
