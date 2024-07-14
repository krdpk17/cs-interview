// Can you comment on the amount of memory malloced by the 'vec' after call to foo()?
#include<list>
#include<map>
#include<iostream>
std::list<int> free_list;
std::map<int, int> allocated_list;
int size = 10;

int   alloc_locker_id(){
  //remove from free list
  if(free_list.empty()){
    return -1;//no locker available
  }
  int id = free_list.front();
  free_list.pop_front();
  //add to alloc table
  allocated_list[id] = 1;
  return id;
}

void  free_locker_id(int id) {
  if(id >= size){
    return;//id out of bound
  }
  if(allocated_list.find(id) == allocated_list.end()){
      return;//freeing without allocation or id out of bound
  }
  allocated_list.erase(id);//remove from the map
  free_list.push_back(id);//add to free list

}

int 
main() {
    //initialize free list
    for(int i = 0; i < size; ++i){
      free_list.push_back(i);
    }
  /*test code*/
    int id;
    for(int j=0; j<11;++j){
      id = alloc_locker_id();
      std::cout<<"Allocated "<<id<<std::endl;
    }

    free_locker_id(5);
    id = alloc_locker_id();
    std::cout<<"Allocated "<<id<<std::endl;
    return(0);
}

/*
preprocessing -> I will allocate vector of size 1000
*/


/*
Locker - 1000
Locker-id
  0-999

Observations:
i th id represent ith locker
What to do if no free locker
  return -1
1000-> configurable?
  For now, we can use fix number 10 for now
I don't worry time of usage

Error case:
  free without allocation -> yes
    logs are enough.. for now, just handle gracefully
  id out of bound -> yes
Memory availability
  data structure -> no specific restriction

*/