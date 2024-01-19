/*
Problem Statement:
Given n rings, move from tower A to tower C using B as auxillary. 
Output: the number of steps
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
enum class TOWER{
    A,
    B,
    C
};

class TowerOfHonai{
    public:
    static int move(int n, TOWER A, TOWER C, TOWER B){
        int steps;
        if(n==0 || n==1){
            return n;
        }
        steps = move(n-1,A,B,C);
        ++steps;
        steps += move(n-1,B,C,A);
        return steps;

    }
};

int main(int argc, char *argv[]){
    if(argc != 2){
        cerr<<"Insufficient number of arguments";
        return -1;
    } 
    int n = atoi(argv[1]);
    int steps = TowerOfHonai::move(n,TOWER::A,TOWER::C,TOWER::B);
    std::cout<<"number of steps to move "<<n<<" rings from tower A to C is"<<steps;
    return 0;

}