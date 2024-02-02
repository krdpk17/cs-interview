#include<algorithm>
class Solution {
public:
    static bool compareDescending(const string& a, const string& b){
        return a>b;
    }

    bool foundMatchedWords(string& s, vector<string>& wordDict, vector<string>& matchedWords){
        bool found = false;
        for(vector<string>::iterator it=wordDict.begin(); it != wordDict.end(); ++it){
            string& word = *it;
            if((s.length()>=word.length())
                && (s.compare(0, word.length(), word) == 0)){
                found = true;
                matchedWords.push_back(word);
            }
        }

        return found;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //bool canBreak = false;
        std::sort(wordDict.begin(), wordDict.end(), compareDescending);
        vector<string> matchedWords;
        if(s.length() == 0){ return true;}
        if(foundMatchedWords(s, wordDict, matchedWords) == false){//no word can match
            return false;
        }

        for(vector<string>::iterator it=matchedWords.begin(); it != matchedWords.end(); ++it){
            string& matchedWord = *it;
            string substr = s;
            substr.erase(0, matchedWord.length());
            if(wordBreak(substr, wordDict)){
                return true;
            }
        }

        return false;
    }
};