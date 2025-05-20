#remove跟len不太熟
class node:
    def __init__(self,x):
        self.data=x
        self.next=None
class Cirlink:
    def __init__(self):
        self.head=None
    def inserthead(self,x):
        self.head=node(x)
        self.head.next=self.head
    def insert(self,x,y):
        tmp=self.head
        newdata=node(y)
        while True:
            if tmp.data==x:
                break
            tmp=tmp.next
        newdata.next=tmp.next
        tmp.next=newdata
    def remove(self,x):
        tmp=self.head.next
        before =self.head
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
    def lengh(self):
        count=0
        if self.head==None:
            return 0
        else:
            tmp=self.head.next
            while tmp!=self.head:
                count=count+1
                tmp=tmp.next
            return count+1 
    def printlist(self):
        len=self.lengh()
        tmp=self.head
        for i in range(len):
            print(tmp.data,end="")
            tmp=tmp.next
l=Cirlink()
l.inserthead(1)
l.insert(1,2)
l.insert(2,3)
l.remove(1)
l.remove(2)
l.printlist()
        

        
        