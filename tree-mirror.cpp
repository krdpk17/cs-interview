#include<stdlib.h>
#include<iostream>
#include<list>
#include<assert.h>
using namespace std;

struct TreeNode{
        TreeNode *lChild;
        TreeNode *rChild;
        int value;
        TreeNode(int v=0){
            this->value = v;
            this->lChild = nullptr;
            this->rChild = nullptr;
        }

};

class MyTree{
    public:
        MyTree(int v=0){
            this->root = new TreeNode(v);
        }

        void insertLeft(TreeNode *parentNode, TreeNode *childNode){
            parentNode->lChild = childNode;
        }

        void insertRight(TreeNode *parentNode, TreeNode *childNode){
            parentNode->rChild = childNode;
        }

        void mirrorTree(){
            mirrorNodes(root);
        }

        TreeNode *getRootNode(){
            return root;
        }
        
        static MyTree *createTree(int n){
            if(n==0){
                return nullptr;
            }

            int i = 1;
            TreeNode *temp = nullptr;//pointer to store parent node
            TreeNode *newNode = nullptr;//pointer to store new node
            list<TreeNode *> tnodeList;// To temporary store nodes for creating balanced tree 
            MyTree *tree = new MyTree(i);
            tnodeList.push_back(tree->getRootNode());
            ++i;

            while(i<=n){
                assert(!tnodeList.empty());
                temp = tnodeList.front();
                if(temp->lChild && temp->rChild){
                    tnodeList.pop_front();
                    continue;
                }
                newNode = new TreeNode(i);
                if(!temp->lChild){
                    temp->lChild = newNode;
                }else{
                    temp->rChild = newNode;
                }
                tnodeList.push_back(newNode);
                ++i;
            }
            return tree;
        }

        void printTree(){
            list<TreeNode *> tnodeList;//Node list
            TreeNode *tempNode = nullptr;// temp node to hold intermediate nodes
            if(root){
                tnodeList.push_back(root);
            }
            
            while(!tnodeList.empty()){
                tempNode = tnodeList.front();
                cout<<tempNode->value<<" ";
                tnodeList.pop_front();
                if(tempNode->lChild){
                    tnodeList.push_back(tempNode->lChild);
                }

                if(tempNode->rChild){
                    tnodeList.push_back(tempNode->rChild);
                }
            }
            return;
        }
    private:
        TreeNode *root;
        void mirrorNodes(TreeNode *node){

            TreeNode *tempNode = nullptr;
            if(!node){
                return;
            }

            if(node->lChild){
                mirrorNodes(node->lChild);
            }

            if(node->rChild){
                mirrorNodes(node->rChild);
            }

            tempNode = node->lChild;
            node->lChild = node->rChild;
            node->rChild = tempNode;
            return;
        }
};

int main(int argc, char *argv[]){
    int n = 5;
    if(argc != 2){

        cerr<<"Invalid number of arguments.. using default value "<<n<<endl;
    }
    else{
        n = atoi(argv[1]);
    }
    MyTree *tree = MyTree::createTree(n);
    cout<<"Original tree in BFS is ";
    tree->printTree();
    cout<<endl;
    tree->mirrorTree();
    cout<<"Mirrored tree in BFS is ";
    tree->printTree();
    cout<<endl;
    return 0;
}