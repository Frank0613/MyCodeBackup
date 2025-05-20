class Stack:
    def __init__(self,size):
        self.size=size
        self.data=[0]*self.size
        self.go=-1
    def isfull(self):
        return self.go==self.size-1
    def isempty(self):
        return self.go==-1
    def push(self,x):
        if self.isfull():
            print('full')
        else:
            self.go+=1
            self.data[self.go]=x
    def pop(self):
        if self.isempty():
            print('empty')
        else:
            item=self.data[self.go]
            self.go-=1
            return item
    def printstack(self):
        for i in range(self.go+1):
            print(self.data[i],end='')
        print(end='\n')
li=Stack(5)
for i in range(1,5):
    li.push(i)
    li.printstack()
for i in range(1,5):
    li.pop()
    li.printstack()  

