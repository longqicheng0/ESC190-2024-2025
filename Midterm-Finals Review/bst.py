class MySet:
    def __init__(self):
        self.data = []
    
    def insert(self, elem):
        if elem not in self.data:
            self.data.append(elem)
    
    def is_in(self, elem):
        return elem in self.data
    
class MyDict:
    def __init__(self):
        self.data = []
    
    def insert(self, key, value):
        if key not in self.data:
            self.data.append((key, value))
    
    def is_in(self, key):
        for k, v in self.data:
            if k == key:
                return True
        return False
    
    def get(self, key):
        for k, v in self.data:
            if k == key:
                return v
        return None