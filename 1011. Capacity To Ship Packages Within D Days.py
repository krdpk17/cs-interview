import math
class Solution(object):
    def check_days_with_capacity(self, capacity, weights, days):
        count = len(weights)
        curr_weight = 0
        start_index = 0
        end_index = count - 1
        day = 0
        for index in range(count):
            curr_weight += weights[index]
            if(curr_weight > capacity):
                day += 1
                curr_weight = weights[index]
                start_index = index
                #print(start_index)
        
        if(start_index <= end_index):
            day += 1 # for remaining weights
        print(capacity, day)
        return day

    def calculate_min_capacity(self, min_capacity, max_capacity, weights, days):
        day_count = 0
        for capacity in range(max_capacity, min_capacity - 1, -1):
            print(capacity)
            day_count = self.check_days_with_capacity(capacity, weights, days)
            if(day_count > days):
                break
        
        if(day_count > days):
            if(capacity < max_capacity):
                capacity += 1

        return capacity


    def shipWithinDays(self, weights, days):
        """
        :type weights: List[int]
        :type days: int
        :rtype: int
        """
        min_capacity = max(weights)
        max_capacity = math.ceil(max(weights) * (len(weights) * 1.0 / days))
        max_capacity = int(max_capacity)
        return self.calculate_min_capacity(min_capacity, max_capacity, weights, days)
        #print(type(min_capacity), type(max_capacity))
        
