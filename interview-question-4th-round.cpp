#include <iostream>
using namespace std;
struct node{
  int m_val;
  struct node *lchild;
  struct node *rchild;
};

int find2ndLargest(node * root, int visited_node_cnt){
  //check if tree has atleast 2 nodes and return if not
  if(!root){
    return 0;
  }
  int ret_val;
  //int visited_node_cnt = 0;
  if(root->rchild){
    ret_val = find2ndLargest(root->rchild, visited_node_cnt);
    if(ret_val != -1){
      visited_node_cnt += ret_val;
    }
  }
  if(visited_node_cnt == 1){
    cout<<"2nd largest node is "<<root->m_val;
    return -1;
  }else if(visited_node_cnt == -1){
    return -1;//break the recursion
  }
  ++visited_node_cnt;

  
  if(root->lchild){
    ret_val = find2ndLargest(root->lchild, visited_node_cnt);
    if(ret_val != -1){
      visited_node_cnt += ret_val;
    }
  }
  return visited_node_cnt;

}

void find2ndLargest(node *root){
  find2ndLargest(root, 0);
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const char* const& word : words) {
    cout << word;
  }
  return 0;
}

//                          50
//              30
//        20          31
//    1                  45
// 2nd largest: 45

//  Enjoy your interview!
//BST
//                          50
//              30                     90
//        20          31         85             95
//    1                  45    80    86
// 2nd largest: 90

//                          50
//              30                     90
//        20          31         85
//    1                  45    80    86
// 2nd largest: 86

