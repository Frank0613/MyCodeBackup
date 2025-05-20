class Node: ##鏈結初始化
  def __init__(self,x): #宣告箱子          
    self.data=x #我的箱子裡要放資料x
    self.next=None #因為還需要放下一個先把next設none，告訴他我還要放
#------------------------------------------------------------藍圖
class LinkedList: ##開始連接箱子
  def __init__(self): #預設的Head  
    self.head=None #第一個箱子
#------------------------------------------------------------head
  def insertHead(self,x):#新增Head以後第一個節點
    self.head=Node(x) #把第一個箱子裝進x資料
#------------------------------------------------------------第一個節點
  def insert(self,y,z):#在y資料後面插入z資料
    tmp=self.head#先設個暫存變數存第一個箱子的東西
    nodex=Node(z) #新的箱子裝新的值
    while True:#掃描整個串列
      if tmp.data==y:#如果暫裡的資料是y，結束迴圈(插入點)
        break
      tmp=tmp.next#暫存去存下一個值
    nodex.next=tmp.next#新箱子的下一個=舊箱子的下一個
    tmp.next=nodex#舊箱子的下一個=新箱子
#------------------------------------------------------------插入
  def remove(self,x):#刪除節點x
    tmp=self.head#新增一個Tmp暫存最前面的箱子
    while True:#掃描整個串列
      if tmp.data==x:#如果找到x(要刪除的)，當找到時就會斷掉，tmp就會是x的上一個節點
        break
      before=tmp#設一個before存要刪除的值的上一個，
      tmp=tmp.next#要刪除的
    if tmp==self.head:#如果刪除的是頭
      self.head=self.head.next#把頭往後移舊好
    else:
      before.next=tmp.next#前一個的下一個就是刪除的下一個
#------------------------------------------------------------   刪除
  def printLinkedList(self):
        tmp=self.head
        while tmp != None:
            print(tmp.data,end=",")
            tmp=tmp.next
#------------------------------------------------------------印出
li=LinkedList()
li.insertHead(5)
li.insert(5,6)
#li.insert(6,7)
#li.insert(5,4)
li.printLinkedList()