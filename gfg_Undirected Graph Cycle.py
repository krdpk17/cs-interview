# Geek for geek question https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
'''
Approach:-
<<Overall approach>>
1. Create adjancancy matrix where edges are neighbor of both nodes
2. Then start with first node and check if connected component has cycle or not
3. Remove all traversed node
4. Repeat the process for remaining untouched nodes

How to check if connected component has cycle or not
1. Check if node is visited again. 
1.1 Remember to filter out false alarm due to undirected graph nature
1.2 To do this, remove both edges from adjacency matrix if once is traversed

'''
class Solution:
    def make_adj_matrix(self, V, edges):
        adj_matrix = {}
        for node in range(V):
            adj_matrix[node] = set()
        for edge in edges:
            node_i = edge[0]
            node_j = edge[1]
            #print(node_i, node_j, edge)
            if(node_i not in adj_matrix):
                adj_matrix[node_i] = set()
            adj_matrix[node_i].add(node_j)
            if(node_j not in adj_matrix):
                adj_matrix[node_j] = set()
            adj_matrix[node_j].add(node_i)
        
        return(adj_matrix)

    def find_cycle(self, V, edges, s_node, adj_matrix, tr_adj_matrix, visited):
        queue = []
        queue.append(s_node)
        #visited = []
        for node in range(V):
            tr_adj_matrix[node] = set()
        while(len(queue) > 0):
            fnode = queue.pop(0)
            visited.append(fnode)
            for node in adj_matrix[fnode]:
                #print(fnode, node, visited, adj_matrix[node])
                if node in tr_adj_matrix[fnode]:
                    continue
                if(node in visited or node in queue):
                    return True
                tr_adj_matrix[node].add(fnode)
                tr_adj_matrix[fnode].add(node)
                queue.append(node)
        return False

    def isCycle(self, V, edges):
        #Code here
        #print(V, edges)
        adj_matrix = self.make_adj_matrix(V, edges)
        #print(adj_matrix)
        tr_adj_matrix = {}
        while(len(adj_matrix) > 0):
            s_node = next(iter(adj_matrix))
            #print(s_node, adj_matrix)
            visited = []
            if(self.find_cycle(V, edges, s_node, adj_matrix, tr_adj_matrix, visited) == True):
                return True
            for node in visited:
                del adj_matrix[node]
        return False

def main():
        V = 4
        edges = [(0, 1), (0, 2), (1, 2), (2, 3)]
        solution = Solution()
        expected = True
        actual = solution.isCycle(V, edges)
        print("expected:", expected, "actual:", actual)

        V = 5
        edges = [(0, 4), (1, 2), (1, 4), (2, 3), (3, 4)]
        solution = Solution()
        expected = True
        actual = solution.isCycle(V, edges)
        print("expected:", expected, "actual:", actual)

        V = 5
        edges = [(0, 4), (1, 2), (1, 4), (2, 3)]
        solution = Solution()
        expected = False
        actual = solution.isCycle(V, edges)
        print("expected:", expected, "actual:", actual)

        V = 5
        edges = [(1, 2), (2, 3)]
        solution = Solution()
        expected = False
        actual = solution.isCycle(V, edges)
        print("expected:", expected, "actual:", actual)

if __name__ == "__main__":
    main()