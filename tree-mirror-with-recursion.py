'''
Mirror of a given tree
'''
class TreeNode:
    def __init__(self, val):
        self.lChild = None
        self.rChild = None
        self.val = val
    
class MyTree:
    def __init__(self, val):
        self.root = TreeNode(val)

    def createTree(self, n):
        if(n == 0):
            return None
        
        treeList = []
        i = 1
        root = TreeNode(1)
        treeList.insert(0, root) #enqueue
        i += 1
        while( i<=n ):
            node = treeList.pop()
            if(node.lChild == None):
                #fill left child
                node.lChild = TreeNode(i)
                treeList.append(node) # put back node to queue
                treeList.insert(0, node.lChild) #enqueue
            elif(node.rChild == None):
                #fill right child
                node.rChild = TreeNode(i)
                #treeList.append(node)
                treeList.insert(0, node.rChild) #enqueue
            else:
                #both children are done 
                continue
            i += 1
        return root

    def printTree(self, root):
        if(root == None):
            return None
        
        treeList = []
        treeList.insert(0, root) #enqueue
        while( len(treeList) ):
            node = treeList.pop()
            print(" " + str(node.val))
            if(node.lChild is not None):
                treeList.insert(0, node.lChild) #enqueue
            if(node.rChild != None):
                treeList.insert(0, node.rChild) #enqueue
        return

    def mirrorTree(self, root):
        if(root is None):
            return
        self.mirrorTree(root.lChild) # mirror left subtree
        self.mirrorTree(root.rChild) # mirror right subtree

        #swap left and right subtrees
        temp = root.lChild
        root.lChild = root.rChild
        root.rChild = temp
        return root


if(__name__ == "__main__"):
    n = 5
    t = MyTree(n)
    root = t.createTree(n)
    print("Original tree is:")
    t.printTree(root)

    t.mirrorTree(root)
    print("Mirrored tree is:")
    t.printTree(root)


