class stack:
    def __init__(self):
        self.data = []
        
    def push(self, elem):
        self.data.append(elem)
    
    def pop(self):
        return self.data.pop()
    
if __name__ == '__main__':
    s = stack()
    s.push(5) #5
    s.push(10) #10
               #5
    
    print(s.pop()) #10
    
            #5
    
    s.push(15) #15
               #5
               
    print(s.pop()) #15
    