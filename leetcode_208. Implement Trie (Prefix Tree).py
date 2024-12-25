class Node:
    def __init__(self, word):
        self.children = {}
        self.val = word
        self.ends = False

class Trie:

    def __init__(self):
        self.root = Node('')
        self.root.ends = True
        

    def insert(self, word: str) -> None:

        #curr_parent = self.root
        curr_node = self.root

        common_prefix = ""
        for alphabet in word:
            #identify common prefix
            print(alphabet)
            if(alphabet in curr_node.children):
                common_prefix += alphabet
                #curr_parent = curr_node
                curr_node = curr_node.children[alphabet]
                continue
            else:
                break

        rem_word = word[len(common_prefix):]
        print(word, rem_word)

        if(not rem_word):
            #word is already part of the some other word
            curr_node.ends = True
            return

        for alphabet in rem_word:
            #Insert suffix in the tree
            curr_node.children[alphabet] = Node(alphabet)
            curr_node = curr_node.children[alphabet]

        curr_node.ends = True


            
        

    def search(self, word: str) -> bool:
        curr_node = self.root
        for alpha in word:
            if(alpha in curr_node.children):
                curr_node = curr_node.children[alpha]
            else:
                return False
        if(curr_node.ends == True):
            return True
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        curr_node = self.root
        for alpha in prefix:
            if(alpha in curr_node.children):
                curr_node = curr_node.children[alpha]
            else:
                return False
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
