#include<memory>
#include<iostream>
using namespace std;
struct Node{
    Node(int value){
        val = value;
        next = NULL;
    }
    int val;
    struct node *next;
};

class Test{
public:
    Test(int val){
        mylist = make_shared<Node>(val);
        cout<<mylist->val;
    }
private:
    shared_ptr<Node> mylist; 
};

int main(){
        int val = 10;
        Node *my_node = new Node(val);
        shared_ptr<Node> existing(my_node);
        val = 20;
        shared_ptr<Node>  myslist = make_shared<Node>(val);
        cout<<myslist->val<<endl;
        myslist = existing;
        cout<<myslist->val<<endl;
        //shared_ptr<Node>  myslist2 = make_shared<Node>(my_node);
        Test test(val);
    return 0;
}