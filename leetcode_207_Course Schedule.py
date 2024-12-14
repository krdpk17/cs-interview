class Node:
    def __init__(self, val):
        self.m_val = val
        self.children = set()
        self.visited = False

    def addChild(self, child):
        self.children.add(child)

    def setVisited(self, visited):
        self.visited = visited

class Solution:
    def getNode(self, nodeMap, prerequisite, index):
        val = prerequisite[index]
        if(nodeMap and val in nodeMap):
            return nodeMap[val]
        node = Node(val)
        nodeMap[val] = node
        return node

    def buildGraph(self, prerequisites) -> Node:
        graphPool = set()
        nodeMap = {}
        for prerequisite in prerequisites:
            print(prerequisite)
            node = self.getNode(nodeMap, prerequisite, 0)
            prerequisite_node = self.getNode(nodeMap, prerequisite, 1)
            prerequisite_node.addChild(node)
                
            if(node in graphPool):
                graphPool.remove(node)
                graphPool.add(prerequisite_node)

            if(not graphPool):
                graphPool.add(prerequisite_node)
        return graphPool

    def checkDAG(self, root) -> bool:
        bfs_queue = []
        bfs_queue.append(root)
        while(bfs_queue):
            node = bfs_queue[0]
            node.visited = True
            bfs_queue.pop(0)
            for child in node.children:
                if(child.visited == True):
                    return False
                bfs_queue.append(child)
        return True



    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graphPool = self.buildGraph(prerequisites)
        print(len(graphPool))
        for graph in graphPool:
            if not self.checkDAG(graph):
                return False
        return True
        
