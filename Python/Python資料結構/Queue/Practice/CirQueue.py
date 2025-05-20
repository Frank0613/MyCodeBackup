#印出那裏
#取餘數邏輯
class CirQueue:
    def __init__(self,size):
        self.size=size
        self.data=[0]*self.size
        self.go=0
        self.out=0
    def isempty(self):
        return self.go==self.out
    def isfull(self):
        return (self.go+1)%self.size==self.out
    def enQueue(self,x):
        if self.isfull():
            print('full')
            return
        else:
            self.data[self.go]=x
            self.go=(self.go+1)%self.size
    def deQueue(self):
        if self.isempty():
            print('empty')
            return
        else:
            item=self.data[self.out]
            self.out=(self.out+1)%self.size
            return item
    def printQueue(self):
        if not self.isempty():
            if self.go>self.out:
                for i in range(self.out,self.go):
                    print(self.data[i],end="")
                print(end='\n')
            else:
                for i in range(self.out,self.size):
                    print(self.data[i],end="")
                print(end='\n')
                for i in range(0,self.go):
                    print(self.data[i],end="")
                print(end='\n')
                

li=CirQueue(5)
for i in range(1,5):
    li.enQueue(i)
    li.printQueue()
li.deQueue()
li.deQueue()
li.printQueue()
li.enQueue(5)
li.printQueue()
#for i in range(1,3):
    #li.deQueue()
    #li.printQueue()
