#甚麼時候加.data要分清楚
#刪除要注意有幾種結果
class node:
    def __init__(self,x):
        self.next=None
        self.data=x
class LinkedList:
    def __init__(self):
        self.head=None
    def inserthead(self,x):
        self.head=node(x)
    def insert(self,x,y):
        tmp=self.head
        nodex=node(y)
        while True:
            if tmp.data==x:
                break
            tmp=tmp.next
        nodex.next=tmp.next
        tmp.next=nodex 
    def remove(self,x):
        tmp=self.head
        while True:
            if tmp.data==x:
                break
            before=tmp
            tmp=tmp.next
        if tmp==self.head:
            self.head=self.head.next
        else:
            before.next=tmp.next
    def Printlist(self):
        tmp=self.head
        while tmp != None:
            print(tmp.data,end=",")
            tmp=tmp.next

l=LinkedList()
l.inserthead(1)
l.insert(1,2)
l.insert(2,3)
l.insert(2,4)
l.remove(4)
l.remove(1)
l.Printlist()
        