class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.val = value

def make_Tree():
    root = Node(1)
    root.left = Node(4)
    root.right = Node(5)
    root.right.left = Node(7)
    return root
    
def calc_sum(cur):
    if (cur == None):
        return 0
    return cur.val + calc_sum(cur.left) + calc_sum(cur.right)


root = make_Tree()
print(calc_sum(root))