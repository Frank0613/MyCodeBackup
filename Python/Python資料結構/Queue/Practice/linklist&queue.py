class Node:
    def __init__(self,x):
        self.next=None
        self.data=x
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
            self.head=self.head.next
            return self.head
        else:
            print('empty')
    def PrintList(self):
        tmp=self.head
        while tmp!=None:
            print(tmp.data,end='')
            tmp=tmp.next
q=Queue()
q.deQueue()
q.enQueueHead(1)
q.PrintList()
print(end='\n')
for i in range(2,6):
    q.enQueue(i)
    q.PrintList()
    print(end="\n")
for i in range(1,7):
    q.deQueue()
    q.PrintList()
    print(end="\n")
q.PrintList()