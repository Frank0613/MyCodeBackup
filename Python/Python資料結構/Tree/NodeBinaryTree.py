class Node:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None
class Binary_Tree:
    def __init__(self,x):
        self.root=Node(x)
    def insertRight(self,node,x):
        if node.right==None:
             node.right=Node(x)
        else:
            newNode=Node(x)
            newNode.right=node.right
            node.right=newNode
    def insertLeft(self,node,x):
        if node.left==None:
             node.left=Node(x)
        else:
            newNode=Node(x)
            newNode.left=node.left
            node.left=newNode
    def preorder_traversal(self,node):#前序
        if node!=None:
            print(node.val,end='')
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
B=Binary_Tree(1)
root=B.root
B.insertLeft(root,2)
B.insertRight(root,3)
B.insertLeft(root.left,4)
B.insertRight(root.left,5)
B.insertLeft(root.right,6)
B.insertRight(root.right,7)

B.preorder_traversal(root)
print('\n')
B.inorder_traversal(root)
print('\n')
B.postorder_traversal(root)        

        