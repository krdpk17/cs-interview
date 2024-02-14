/*
Question:
1. Create a data structure for Trie
2. Add functionality for adding a string
*/

#include<list>
#include<string>
#include<queue>
#include<iostream>
using namespace std;
struct TrieNode{
  char m_c;
  TrieNode * child[26];
  int child_count;
  TrieNode(char c){
    this->m_c = c;
    this->child_count = 0;
  }
};

/*
Class responsible to maintain Trie
*/

class TrieString{
public:
  TrieString(){
    m_root = new TrieNode('0');//keep dummy character
  }

    void printTree(){
        TrieNode *curr_node = m_root;
        list<TrieNode *> trie_queue;
        trie_queue.push_back(m_root);

        cout<<endl;
        while(!trie_queue.empty()){
            curr_node = trie_queue.front();
            trie_queue.pop_front();
            cout<<" "<<curr_node->m_c;
            // insert all children to queue
            for(int i = 0; i <curr_node->child_count; ++i){
                trie_queue.push_back(curr_node->child[i]);
            }
        }

    }
/*
  It takes parent node and char as input
  It first finds if any child node is having char
  If yes, return this child node
  If not, insert the new child node in Trie and then return new node
  Assumption: Parent node is not NULL
    c is one of 26 characters ranging from 'a' to 'z'
*/
  TrieNode * insert_char(TrieNode *parent_node, char c){
    TrieNode *temp_node = NULL;
    int i;
    /*
    if(child_count == 0){
      //need to add the char as new child node
      temp_node = new TrieNode(c);
      child[0] = temp_node;
      ++child_count;
      return temp_node;
    }*/
    
    for(i = 0; i<parent_node->child_count; ++i){
      temp_node = parent_node->child[i];
      if(temp_node->m_c == c){//found the child node with char
        return temp_node;
      }
    }

      temp_node = new TrieNode(c);
      parent_node->child[i] = temp_node;
      ++parent_node->child_count;
      return temp_node;
  }
/*
It inserts the string to Trie
Uses helper API insert_char responsible to insert each char from left to right
*/
  bool insert(string str){
    int len = str.length();
    int i;
    TrieNode *parent_node = m_root;
    for(i=0; i <= len; ++i){
      parent_node = insert_char(parent_node, str[i]);
    }

    return true;
  }

private:
   TrieNode *m_root;

};


int main(){

    TrieString myTrie;
    myTrie.insert("abcd");
    myTrie.printTree();
    myTrie.insert("abd");
    myTrie.printTree();
    myTrie.insert("acd");
    myTrie.printTree();
    return 0;
}