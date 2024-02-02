class Solution {
public:
    /*
        This recursive function checks two cases
        1. Number of combinations by keeping first element
        2. Number of combinations by not keeping first element
        Note that This code doesn't repeat the same combination. 
        For example, (1,1,2) and (1,2,1) both are counted one
    */
    int combinationSum4WithStartIndex(vector<int>& nums, int sIndex, int target, int &totalCount){
        if(target == 0){
            ++totalCount;
            return 1;
        }

        if(nums.size() <= sIndex){
            return 0;
        }
        
        int firstitemsum;
        //cout<<sIndex<<" ";
        //swap the values and try for all permutations
        int temp;
        for(int i = sIndex; i<nums.size(); ++i){
            temp = nums[sIndex];
            nums[sIndex] = nums[i];
            nums[i] = temp;
            for(firstitemsum = nums[sIndex]; firstitemsum <= target;  firstitemsum += firstitemsum){
                //Check how many can be formed including 1st item
                combinationSum4WithStartIndex(nums, sIndex + 1, target - firstitemsum, totalCount);
            }
        }

        //check how many can be formed excluding 1st item
        combinationSum4WithStartIndex(nums, sIndex + 1, target, totalCount);
        return totalCount;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int totalCount = 0;
        combinationSum4WithStartIndex(nums, 0, target, totalCount);
        return totalCount;
    }
};