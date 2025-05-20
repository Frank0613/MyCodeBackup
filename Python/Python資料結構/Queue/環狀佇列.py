class CirQueue:
  def __init__(self,size):
    self.size=size
    self.data=[0]*self.size 
    self.front=0 
    self.back=0
  def isFull(self): #佇列已滿的情況
    return self.front==((self.back+1)%self.size)
  def isEmpty(self): #佇列是空的情況
    return self.back==self.front
  def enQueue(self,x): #佇列加入
    if self.isFull(): #滿了印出已滿
      print('佇列是滿的')
    else:
      self.data[self.back]=x #給值
      self.back=(self.back+1)%self.size
  def deQueue(self,x): #佇列拿出
    if self.isEmpty(): #空了印出是空的
      print('佇列是空的')
    else:
      item=self.data[self.front] #front+1
      self.front=(self.front+1)%self.size
      return item #給值
  def printQueue(self):
    if not self.isEmpty():
      if self.back>self.front:
        for i in range(self.front,self.back): #範圍在前面到後面
          print(self.data[i],end="")
      else:
        for i in range(self.front,self.size):
          print(self.data[i],end="")
        for i in range(0,self.back):
          print(self.data[i],end="")