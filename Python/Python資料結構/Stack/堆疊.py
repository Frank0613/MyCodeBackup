class Stack:
    def __init__(self,size):
        self.size=size
        self.data=[0]*self.size
        self.top=-1
    def IsFull(self):
        return self.top==self.size-1
    def IsEmpty(self):
        return self.top==-1
    def Push(self,x):
        if self.IsFull():
            print("滿了")
        else:
            self.top+=1
            self.data[self.top]=x
    def Pop(self):
        if self.IsEmpty():
            print('空的')
        else:
            item=self.data[self.top]
            self.top-=1
        return item
    def printStack(self):
        for i in range(0,self.top+1):
            print(self.data[i],end="")
        print()
St=Stack(4)
for i in range(1,5):
    St.Push(i)
    St.printStack()
for i in range(1,5):
    St.Pop()
    St.printStack()    
        

