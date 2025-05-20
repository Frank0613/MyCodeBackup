class Node:
    def __init__(self,x):
        self.data=x
        self.next=None
class Queue:
    def __init__(self):
        self.head=None
    def enQueueHead(self,x):
        self.head=Node(x)
        self.count=self.head
    def enQueue(self,x):
        self.count.next=Node(x)
        self.count=self.count.next
    def deQueue(self):
        if self.head!=None:
            item=self.head
            self.head=self.head.next
            return item.data
        else:
            print('空')
    def PrintList(self):
        tmp=self.head
        while tmp!=None:
            print(tmp.data,end=",")
            tmp=tmp.next
        
q=Queue()
q.deQueue()
q.enQueueHead(1)
for i in range(2,6):
    q.enQueue(i)
    q.PrintList()
    print(end="\n")
for i in range(1,7):
    q.deQueue()
    q.PrintList()
    print(end="\n")
q.PrintList()