/*
Working on taking more time
*/

class Solution {

public:
    bool checkPalandromeStr(string s, int start, int end){
        int i = start;
        int j = end;
        while(i<j){
            if(s[i] != s[j]){ return false;}
            ++i;
            --j;
        }
        return true;
    }

    /*
        Find palandrome starting from first char of the string
    */
    string longestPalandromeWithFirstChar(string s){
        int len = s.length();
        int i;
        int end_index = 0;
        char c = s[0];
        for(i=1; i < len; ++i){
            if(s[i] == c){
                //check if string s[1].. s[i-1] is palandrome
                if(checkPalandromeStr(s, 1, i-1)){// yes. so, record the end of palandrome
                    end_index = i;
                }
            }
        }
        //calculate palandromic substring size
        string sub = s.substr(0, end_index + 1);
        return sub;
    }

    string longestPalindrome(string s) {
        //Get the largest paladrome keeping first char
        // Get the largest palandrome without keeping first char
        int len = s.length();
        if(len <=1 ){//string itself is palandrome
            return s;
        }

        string palandromeWithFirstChar = longestPalandromeWithFirstChar(s);
        string substrWithoutFirstChar = s.substr(1, s.length()-1);
        string palandromeWithoutFirstChar = longestPalindrome(substrWithoutFirstChar);

        string result;
        //cout<<"output:";
        //cout<<palandromeWithFirstChar<<" "<<palandromeWithoutFirstChar;
        //cout<<endl;
        if(palandromeWithFirstChar.length()>palandromeWithoutFirstChar.length()){
            result = palandromeWithFirstChar;
        }else{
            result = palandromeWithoutFirstChar;
        }
        return result;
    }
};