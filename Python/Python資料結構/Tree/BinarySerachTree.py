class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None #剛開始根結點是None
        
    def insert(self, val): #插入方法
        if self.root is None: #如果根結點沒東西，插入值
            self.root = Node(val)
        else:
            self._insert(val, self.root) #如果根結點有東西，執行下一個插入方法
            
    def _insert(self, val, node): #node是指當前要比較的節點
        if val < node.val: #如果插入的值比較小
            if node.left is None:
                node.left = Node(val) #插入左邊
            else:
                self._insert(val, node.left) #左邊如果有東西繼續往他左邊插
        elif val > node.val: #如果插入的值比較大(邏輯跟左邊一樣)
            if node.right is None:
                node.right = Node(val)
            else:
                self._insert(val, node.right)
                
    def search(self, val): #這裡是為了使用者方便寫的，只要輸入尋找的值就可以調用_search
        return self._search(val, self.root) #從根節點開始尋找
    
    def _search(self, val, node): #搜尋值是否存在
        if node is None: #節點沒東西回傳False
            return False
        elif val == node.val: #節點值=要找的值回傳True
            return True
        elif val < node.val: #要找的值<根節點值：繼續往左邊找
            return self._search(val, node.left)
        else: #要找的值>根節點值：繼續往左邊找
            return self._search(val, node.right)
        
    def delete(self, val): #刪除(這裡概念跟搜尋一樣)
        self.root = self._delete(val, self.root) #從跟節點開始找要刪除的值
        
    def _delete(self, val, node): 
        if node is None: #如果要刪除的節點不存在，則直接回傳原本的節點
            return node
        elif val < node.val: #小於往左
            node.left = self._delete(val, node.left)
        elif val > node.val: #大於往右 
            node.right = self._delete(val, node.right)
        else:
            if node.left is None: #如果目標節點的左子樹為空，就把目標節點刪除，並返回右子樹。這樣的意思是將右子樹接到目標節點的位置，相當於將目標節點刪除。
                temp = node.right
                node = None
                return temp
            elif node.right is None: #如果目標節點的右子樹為空，就把目標節點刪除，並返回左子樹。這樣的意思是將左子樹接到目標節點的位置，相當於將目標節點刪除。
                temp = node.left
                node = None
                return temp
            temp = self._min_value_node(node.right) #如果目標節點的左右子樹都存在，就找到目標節點右子樹中最小的節點，將其值複製到目標節點上，然後再刪除右子樹中的該節點。
            node.val = temp.val
            node.right = self._delete(temp.val, node.right)
        return node
    
    def _min_value_node(self, node): #找到最小(一定是最左邊)
        while node.left is not None:
            node = node.left #直到走到最左邊
        return node #回傳

#--------------------------------------------------------------------
    def preorder_traversal(self,node):#前序
        if node!=None:
            print(node.val,end=' ')
            self.preorder_traversal(node.left)
            self.preorder_traversal(node.right)
    def inorder_traversal(self,node):#中序
        if node!=None:
            self.inorder_traversal(node.left)
            print(node.val,end=' ')
            self.inorder_traversal(node.right)
    def postorder_traversal(self,node):#後序
        if node!=None:
            self.postorder_traversal(node.left)
            self.postorder_traversal(node.right)
            print(node.val,end=' ')
bst = BinarySearchTree()

bst.insert(8)
bst.insert(3)
bst.insert(10)
bst.insert(1)
bst.insert(6)
bst.insert(14)
bst.insert(4)
bst.insert(7)
bst.insert(13)

print("In-order Traversal：",end='')
bst.inorder_traversal(bst.root)

print("\nPre-order Traversal：",end='')
bst.preorder_traversal(bst.root)

print("\nPost-order Traversal：",end='')
bst.postorder_traversal(bst.root)


