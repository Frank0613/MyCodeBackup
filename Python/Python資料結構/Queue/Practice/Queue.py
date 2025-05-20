class Queue:
    def __init__(self,size):
        self.size=size
        self.data=[0]*self.size
        self.go=-1
        self.out=-1
    def isfull(self):
        return self.go==self.size-1
    def isempty(self):
        return self.go==-1
    def enQueue(self,x):
        if self.isfull():
           print("full")
        else:
           self.go+=1
           self.data[self.go]=x 
    def deQueue(self):
        if self.isempty():
           print('empty')
        else:
           self.out+=1
           return self.data[self.out]
    def printQueue(self):
        for i in range(self.out+1,self.go+1):
           print(self.data[i],end=',')
        print('\n')
q=Queue(4)
for i in range(1,5):
  q.enQueue(i)
  q.printQueue()
for i in range(1,5):
  q.deQueue()
  q.printQueue()