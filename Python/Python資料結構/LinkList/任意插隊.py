class Node:
    def __init__(self,x):
        self.data=x
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    def InsertHead(self,x):
        self.head=Node(x)
    def InsertAt(self,x,pos):#插入x在pos位置
        tmp=self.head
        nodex=Node(x)
        count=2
        if pos==1:#插入在第一個位置
            nodex.next=tmp
            self.head=nodex
        else:
            while count<pos:
                tmp=tmp.next
                count=count+1
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
    def serve(self):
        item=self.head
        self.head=self.head.next
        return item.data
n,m=input().split()
n=int(n)
m=int(m)
li=LinkedList()
li.InsertHead(1)

for i in range(2,n+1):
    li.InsertAt(i,i)
for i in range(m):
    cmd=input()
    if cmd[0] =="s":
        x=li.serve() #把X拿出來
        li.InsertAt(x,n) #把X插到隊伍後面
        print(x)
    else:
        p,x,pos = cmd.split()
        x=int(x)
        li.remove(x)
        pos=int(pos)
        li.InsertAt(x,pos)
    

