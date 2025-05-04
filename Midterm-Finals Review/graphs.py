import LL
import numpy as np
class Graph:
    def __init__(self, num_nodes):
        self.adj_matrix = np.zeros((num_nodes, num_nodes))
    
    def is_edge(self, i, j):
        return self.adj_matrix[i][j] == 1
    
    def put_edge(self, i, j):
        self.adj_matrix[i][j] = 1
    
    def remove_edge(self, i, j):
        self.adj_matrix[i][j] = 0
        
if __name__ == '__main__':
        g = Graph(4)
        g.put_edge(1,2)
        print(g.is_edge(1,2))
    
'''import numpy as np
M = np.array((10,10))
M[0][1]'''

class Graph2:
    def __init__(self, num_nodes):
        self.nodes = [None] * num_nodes
        for i in range(num_nodes):
            self.nodes.append(LL.LL())
    
    def is_edge(self, i, j):
        return self.nodes[i].is_in(j)
    
    def put_edge(self, i, j):
        if self.nodes[i].is_in(j):
            return
        self.nodes[i].insert(0, j)
        
    def remove_edge(self, i, j):
        pass
