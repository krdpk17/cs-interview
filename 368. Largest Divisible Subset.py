# Test case 47/49 resulted in time limit exceed
class Solution(object):
    def build_list(self, curr_index, sorted_nums, new_list):
        len_sorted_nums = len(sorted_nums)
        if(curr_index >= len_sorted_nums):
            print("out of index", new_list, curr_index)
            return new_list
        
        curr_longest = new_list
        #count_new_list = len(new_list)
        while curr_index < len_sorted_nums:
            if(sorted_nums[curr_index] % new_list[-1] == 0):
                #new_list = new_list[:count_new_list]
                copied_list = list(new_list)
                copied_list.append(sorted_nums[curr_index])
                print(copied_list,  curr_index, curr_longest)
                seq_list = self.build_list(curr_index + 1, sorted_nums, copied_list)
                if(len(curr_longest) < len(seq_list)):
                    curr_longest = seq_list
                #print(copied_list, seq_list, curr_index, curr_longest)
            curr_index += 1
            
        return curr_longest

    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        sorted_nums = sorted(nums)
        with_one = False
        if(sorted_nums[0] == 1):
            with_one = True
            sorted_nums = sorted_nums[1:]
        len_sorted_nums = len(sorted_nums)
        print(sorted_nums)

        next_index = 0
        current_longest = []
        while next_index < len_sorted_nums:
            new_list = []
            new_list.append(sorted_nums[next_index])
            curr_index = next_index + 1
            print(new_list, curr_index)
            seq_list = self.build_list(curr_index, sorted_nums, new_list)
            
            if(len(current_longest) < len(seq_list)):
                current_longest = seq_list
            
            next_index += 1
            print("seq list:", seq_list)

        if(with_one):
            current_longest.append(1)
        return current_longest


        
