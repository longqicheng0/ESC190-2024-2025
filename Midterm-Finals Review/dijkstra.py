#visited nodes S = {A,C}
import numpy as np
import heapq
'''pq = heapq.heapify([])
heapq.heappush(pq,[1,2])
heapq.heappush(pq,[2,3])
print(heapq.heappop(pq))'''


class Node:
    def __init__(self, value):
        self.value = value
        self.cons = []
        self.d_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight
        
def dijkstra(start = Node, end = Node):
    start.d_from_start = 0
    visited = set()
    to_be_considered = [(0, {"node": start, "prev": None})]
    cur = start

    #navigate through the graph
    while cur != end:
        '''
        #initial dist set to inf so curdist will update once detect a smaller dist
        cur.dist = np.inf
        #the current connection node with the smallest distance
        cur_v = None
        '''
        
        '''
        #cur will initially be start node and iterate
        for node in visited:
            #check if the current node is in the visited set
            for con in node.cons:
                #nothing happened is already visited
                if con.node in visited:
                    continue
                #if the current node is not visited and the distance is smaller than the current path
                if cur.dist > node.d_from_start + con.weight:
                    cur.dist = node.d_from_start + con.weight
                    cur_v = con.node
                    '''
        cur_dist, cur_dict = heapq.heappop(to_be_considered)
        cur = cur_dict["node"]
        prev = cur_dict["prev"]
        cur.prev = prev
        if cur in visited:
                continue
        cur.d_from_start = cur_dist
        visited.add(cur)

        for con in cur.cons:
            if con.node in visited:
                continue
            heapq.heappush(to_be_considered, (con.weight + cur.d_from_start, {"node": con.node, "prev": cur}))
    return cur.d_from_start