
#include <iostream>
using namespace std;



void reverse(string& str, int sIndex, int eIndex){
  //int size = str.size();//returns string length
  int i;
  int j;
  char temp;
  for(i = sIndex, j = eIndex; i < j; ++i, --j){
    //swap chars;
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
  return;
}

inline bool isSpace(char ch){
  if(ch == ' '){//can extend to add more space types
    return true;
  }else{
    return false;
  }
}

// To execute C++, please define "int main()"
int main() {
  string mystr("I am a boy");
  int size = mystr.size();
  reverse(mystr, 0, size - 1);
  int sIndex = -1;
  int eIndex = -1;
  for(int i=0; i < size; ++i){
    if(isSpace(mystr[i])){
      eIndex = i;
      if(sIndex != -1){//ready to reverse
        reverse(mystr, sIndex, eIndex-1);
      }
      //reset to get next word
      eIndex = -1; 
      sIndex = -1;
    }else if(sIndex == -1){
      sIndex = i;
    }
  }
  cout<<mystr;
  
  return 0;
}