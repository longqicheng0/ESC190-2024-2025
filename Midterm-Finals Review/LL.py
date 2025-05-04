class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class LL:
    def __init__(self):
        self.head = None
    
    def insert(self, idx, data):
        new_node = Node(data)
        
        if self.head == None:
            self.head = new_node
            
        else:
            if idx == 0:
                head_temp = self.head
                self.head = new_node
                self.head.next = head_temp
            else:
                cur = self.head
                for i in range(idx - 1):
                    cur = cur.next

                cur.next, new_node.next = new_node, cur.next
    
    def is_in(self, data):
        cur = self.head
        while cur:
            if cur.data == data:
                return True
            cur = cur.next
        return False
    
    def remove(self, data):
        if (self.head.data == data):
            self.head = self.head.next
            return
        
        cur = self.head
        while cur.next != None and cur.next.data != data:
            cur = cur.next
        
        if cur.next == None:
            print("Data not found")
            return
        cur.next = (cur.next).next
            
        
        
    def print(self):
        cur = self.head
        while(cur != None):
            print (cur.data, "->", end = "")
            cur = cur.next
        print("None")
            

if __name__ == '__main__':
    myLL = LL()
    myLL.insert(0,123)
    myLL.insert(0,125)
    myLL.print()
