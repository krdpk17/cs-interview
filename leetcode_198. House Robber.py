'''
 * This code is working but having time-out issue
 * So, it means that code is not optimal
 * https://leetcode.com/problems/longest-string-chain/ 
'''
class Solution(object):
    def rob_withindex(self, nums, sIndex, curr_sum):
        if(len(nums) == sIndex):
            return curr_sum

        val = nums[sIndex] #take 1st
        sIndex = sIndex + 1
        sum1 = curr_sum + val
        if(len(nums) > sIndex + 1):
            sum1 = self.rob_withindex(nums, sIndex + 1, sum1)
        
        sum2 = 0
        if(len(nums) > sIndex):
            val = nums[sIndex]#take 2nd
            sIndex = sIndex + 1
            sum2 = curr_sum + val
            if(len(nums) > sIndex + 1):
                sum2 = self.rob_withindex(nums, sIndex + 1, sum2)
        
        return max(sum1, sum2, curr_sum)



    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sIndex = 0
        curr_sum = 0
        return self.rob_withindex(nums, 0, 0)