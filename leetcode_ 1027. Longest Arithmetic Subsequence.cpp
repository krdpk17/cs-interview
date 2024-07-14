/*
Code is giving correct result for sample test case.. but timeout happening
So, non-optimal solution.. needs to improve

Leetcode link - https://leetcode.com/problems/longest-arithmetic-subsequence/ 
*/

class Solution {
public:
    int findSubseqLen(vector<int>& nums, int sIndex, int gap){
        int size = nums.size();
        int i = sIndex + 1;
        int currIndex = sIndex;
        int len = 0;
        int distance;
        while(i < size){
            distance = nums[currIndex]-nums[i];
            if(distance == gap){//found a match
                ++len;//count to len
                currIndex = i;//set this in sequence
            }
            ++i;
        }
        return len;
    }

    int longestArithSeqLengthStartsWith(vector<int>& nums, int sIndex){
        int size = nums.size();
        int len;
        int curr_max_len = 0;
        for(int i = sIndex + 1; i < size; ++i){
            int gap = nums[sIndex] - nums[i];
            len = 2;
            len += findSubseqLen(nums, i, gap);
            //cout<<" sIndex="<<sIndex<<" i="<<i<<" gap="<<gap<<" len="<<len<<" curr_max_len="<<curr_max_len<<endl;
            if(len > curr_max_len){
                curr_max_len = len;
            }
        }
        return curr_max_len;
    }

    int longestArithSeqLength(vector<int>& nums, int sIndex) {
        if(sIndex == nums.size() - 1){
            return 0;
        }
        int len_exclusive = longestArithSeqLength(nums, sIndex + 1);
        int len_inclusive= longestArithSeqLengthStartsWith(nums, sIndex);
        //cout<<" "<<sIndex<<" "<<len_exclusive<<" "<<len_inclusive<<endl;
        if(len_inclusive > len_exclusive){
            return len_inclusive;
        }else{
            return len_exclusive;
        }
    }

    int longestArithSeqLength(vector<int>& nums) {
        return longestArithSeqLength(nums, 0);
    }
};