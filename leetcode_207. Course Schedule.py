class Node:
    def __init__(self, val):
        self.m_val = val
        self.m_children = set()
        self.visited = False

    def addChild(self, child):
        self.m_children.add(child)

    def setVisited(self, visited):
        self.visited = visited

class Solution:
    def getNode(self, nodeMap, prerequisite, index) -> (Node, bool):
        val = prerequisite[index]
        if(nodeMap and val in nodeMap):
            return nodeMap[val], False
        node = Node(val)
        nodeMap[val] = node
        return node, True

    def buildGraph(self, prerequisites) -> Node:
        graphPool = set()
        nodeMap = {}
        for prerequisite in prerequisites:
            #print(prerequisite)
            node, newNode = self.getNode(nodeMap, prerequisite, 0)
            prerequisite_node, prerequisite_newNode = self.getNode(nodeMap, prerequisite, 1)
            prerequisite_node.addChild(node)
            
            # Remove node only if parent is new
            if(node in graphPool and prerequisite_newNode):
                graphPool.remove(node)
                #print("Removed node", node.m_val)

            # Either new node or the self loop
            if(prerequisite_newNode or node == prerequisite_node):
                graphPool.add(prerequisite_node)
                #print("Added node", prerequisite_node.m_val)
        return graphPool

    def checkDAG2(self, root) -> bool:
        bfs_queue = []
        bfs_queue.append(root)
        #print("Graph root", root.m_val)
        visited = []
        while(bfs_queue):
            node = bfs_queue[0]
            #node.visited = True
            visited.append(node.m_val)
            bfs_queue.pop(0)
            for child in node.children:
                if(child.m_val in visited):
                    return False
                bfs_queue.append(child)
        return True

    def checkDAG3(self, root, visited, edges_visited) -> bool:
        new_visited = visited.copy()
        new_visited.append(root.m_val)
        print("Graph root", root.m_val)
        if(root.m_children):
            for child in root.m_children:
                pair = (root.m_val, child)
                if(pair in edges_visited):
                    return False
                else:
                    edges_visited.add(pair)
                result = self.checkDAG(child, new_visited, edges_visited)
                if(result == False):
                    return result
        return True

    def checkDAG(self, root, visited, edges_visited) -> bool:
        # Depth first search
        if(root.m_val in visited):
            return False
        new_visited = visited.copy()
        new_visited.append(root.m_val)
        #print("Graph root", root.m_val)
        if(root.m_children):
            for child in root.m_children:
                '''
                pair = (root.m_val, child)
                if(pair in edges_visited):
                    return False
                else:
                    edges_visited.add(pair)
                '''
                result = self.checkDAG(child, new_visited, edges_visited)
                if(result == False):
                    return result
        return True

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graphPool = self.buildGraph(prerequisites)
        print(len(graphPool))
        for graph in graphPool:
            visited = []
            edges_visited = set()
            if not self.checkDAG(graph, visited, edges_visited):
                return False
        return True
        
