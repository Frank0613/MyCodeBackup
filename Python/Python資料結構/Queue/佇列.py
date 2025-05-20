class Queue: #先進先出
  def __init__(self,size): #定義佇列跟大小
    self.size=size #佇列大小是使用者給的大小
    self.data=[0]*self.size #建立空間(裡面是空的)
    self.front=-1 #出口(給-1是因為佇列是會先加1再給值，如果給0那第0格會被跳過)
    self.back=-1 #入口
  def isFull(self): #佇列已滿的情況
    return self.back==self.size-1 #入口在佇列最後面的位置
  def isEmpty(self): #佇列是空的情況
    return self.back==self.front #出口值=入口值
  def enQueue(self,x): #佇列加入
    if self.isFull(): #滿了印出已滿
      print('佇列是滿的')
    else:
      self.back=self.back+1 #back+1
      self.data[self.back]=x #給值
  def deQueue(self): #佇列拿出
    if self.isEmpty(): #空了印出是空的
      print('佇列是空的')
    else:
      self.front=self.front+1 #front+1
      return self.data[self.front] #給值
  def printQueue(self): 
    for i in range(self.front+1,self.back+1): #範圍在前面到後面
      print(self.data[i],end="")
    print()
q=Queue(4)
for i in range(1,5):
  q.enQueue(i)
  q.printQueue()
for i in range(1,5):
  q.deQueue()
  q.printQueue()