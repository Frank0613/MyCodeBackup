class Node:
    def __init__(self,x):
        self.data=x
        self.next=None
        self.pre=None #pre是前一個
class DoubleLinkedList: #雙向鏈結
    def __init__(self):
        self.head=None
    def insertHead(self,x):
        self.head=Node(x)
        self.head.next=self.head #--
        self.head.pre=self.head #--
    def insert(self,y,x):
        tmp=self.head
        nodex=Node(x)
        while True: #true代表永遠執行
            if tmp.data==y:
                break
            tmp=tmp.next
        nodex.next=tmp.next
        nodex.pre=tmp #--
        tmp.next.pre=nodex #--
        tmp.next=nodex
    def remove(self,x):
        tmp=self.head
        while True:
            if tmp.data==x:
                break
            tmp=tmp.next
        if tmp==self.head and self.head.next==self.head: 
            self.head=None
        elif tmp==self.head:
            self.head=tmp.next
        if self.head!=None:
            tmp.pre.next=tmp.next
            tmp.next.pre=tmp.pre
    def len(self):
        count=0
        if self.head==None:
            return 0
        else:
            tmp=self.head.next
            while tmp != self.head:
                count=count+1
                tmp=tmp.next
            return count+1
    def printLinkedList(self):
        length=self.len()
        tmp=self.head
        for i in range(length):
            print(tmp.data,"",end=" ")
            tmp=tmp.next
        print()
li=DoubleLinkedList()
li.insertHead(5)
li.insert(5,6)
li.remove(5)
li.printLinkedList()


