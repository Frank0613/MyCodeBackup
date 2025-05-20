class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# 建立二元樹
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

# 輸出二元樹節點的值
def print_tree(node):
    if node:
        print(node.val)
        print_tree(node.left)
        print_tree(node.right)

print_tree(root)