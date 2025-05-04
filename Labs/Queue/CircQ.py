class CircQ:
    def __init__(self, len):
        self.q = [None]* len
        self.len = len
        self.head = -1
        self.tail = -1
        
    def enqueue(self, num):
        if (self.head == -1):
            self.head = 0
        self.tail = (self.tail + 1) % self.len
        self.q[self.tail] = num
    
    #take the first elem, remove it, change head
    def dequeue(self):
        ret = self.q[self.head]
        self.q[self.head] = None
        
        if (self.head == self.tail):
            self.head = self.tail = -1
        else:
            self.head = (self.head + 1) % self.len
        return ret
    
    def __str__(self):
        res = []
        i = self.head
        while True:
            res.append(self.q[i])
            if i == self.tail:
                break
            i = (i + 1) % self.len
        return str(res)
    
    def tolist(self):
        res = []
        i = self.head
        while True:
            res.append(self.q[i])
            if i == self.tail:
                break
            i = (i + 1) % self.len
        return res
    
    def __lt__(self, other):
        listSelf = self.tolist()
        listOther = other.tolist()
        
        track_len = min(len(listSelf),len(listOther))
        
        for i in range (track_len):
            if listSelf[i] < listOther[i]:
                return True
            elif listSelf[i] > listOther[i]:
                return False
        
        return len(listSelf)<len(listOther)
    
if __name__ == '__main__':
    q = CircQ(6)
    q.enqueue(10)
    q.enqueue(12)
    print("Queue after enqueuing 10 and 12:", q)
    
    q.enqueue(7)
    print("Queue after enqueuing 7:", q)
    
    q.dequeue()
    print("Queue after dequeuing:", q)
    
    q.enqueue(1)
    q.enqueue(6)
    print("Queue after enqueuing 1 and 6:", q)
    
    q.enqueue(15)
    q.enqueue(20)
    print("Queue after enqueuing 15 and 20 (should be full now):", q)
    
    q.dequeue()
    q.enqueue(25)  # This should wrap around
    print("Queue after dequeuing one element and enqueuing 25:", q)
    
    
    q1 = CircQ(2)
    q1.enqueue(1)
    q1.enqueue(3)
    q2 = CircQ(2)
    q2.enqueue(0)
    q2.enqueue(2)
    q3 = CircQ(4)
    q3.enqueue(1)
    q3.enqueue(3)
    q3.enqueue(3)
    q3.enqueue(4)
    
    qs = [q1,q2,q3]
    qs.sort()
    
    print(qs[0])
    print(qs[1])
    print(qs[2])

    
    

            
        