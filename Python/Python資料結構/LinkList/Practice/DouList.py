class node:
    def __init__(self,x):
        self.data=x
        self.next=None
class Doulist:
    def __init__(self):
        self.head=None
    def inserthead(self,x):
        self.head=node(x)
        self.head.next=self.head
        self.head.pre=self.head
    def insert(self,x,y):
        tmp=self.head
        nodex=node(y)
        while True:
            if tmp.data==x:
                break
            tmp=tmp.next
        nodex.next=tmp.next
        tmp.next.pre=nodex
        nodex.pre=tmp
        tmp.next=nodex  
    def remove(self,x):
        tmp=self.head.next
        before=self.head
        while True:
            if tmp.data==x:
                break
            before=tmp
            tmp=tmp.next
        if tmp==self.head and self.head.next==self.head:
            self.head=None
        elif tmp==self.head:
            self.head=self.head.next
            before.next=self.head
        else:
            before.next=tmp.next
            tmp.pre=before.next.pre
    def len(self):
        tmp=self.head.next
        count=0
        if self.head==None:
            return 0
        else:
            while tmp!=self.head:
                count+=1
                tmp=tmp.next
            return count+1
    def printlist(self):
        tmp=self.head
        for i in range(self.len()):
            print(tmp.data,end=",")
            tmp=tmp.next
        
l=Doulist()
l.inserthead(1)
l.insert(1,2)
l.insert(1,3)
l.remove(3)
l.remove(1)
l.printlist()
        