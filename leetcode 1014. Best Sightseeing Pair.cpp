/*
Code is giving correct result for sample test case.. but timeout happening
So, non-optimal solution.. needs to improve

Leetcode link - https://leetcode.com/problems/best-sightseeing-pair/
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int size = values.size();
        int i, j, val_i, val_j;
        int curr_max_score = 0;
        int score;
        for(i=0; i < size; ++i){
            for(j=i+1; j < size; ++j){
                val_i = values[i];
                val_j = values[j];
                score = val_i + val_j + i - j;
                if(curr_max_score < score){
                    curr_max_score = score;
                }
            }
        }
        return curr_max_score;   
    }
};