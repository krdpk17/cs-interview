"""
Code working but time limit exceeding
"""
class Solution(object):        

    def createTiringDaList(self, hours, tiring_or_not_list):
        for hour in hours:
            if (hour <= 8):
                tiring_or_not_list.append(-1)
            else:
                tiring_or_not_list.append(1)
        return 

    def findMaxWPI(self, tiring_or_not_list):
        n = len(tiring_or_not_list)
        prefix_sum = [0 for i in range(0, n)]
        prefix_sum[0] = tiring_or_not_list[0]
        if(prefix_sum[0] > 0):
            curr_max = 1
        else:
            curr_max = 0
            
        for i in range(1, n):
            prefix_sum[i] = prefix_sum[i-1] + tiring_or_not_list[i]
            if(prefix_sum[i] > 0):
                curr_max = i + 1
                
        print(tiring_or_not_list)
        print(prefix_sum)  
        for i in range(1, n):
            sum = 0
            for j in range(i, n):
                sum = prefix_sum[j] - prefix_sum[i - 1]
                if(sum > 0):
                    curr_max = max(curr_max, j-i+1)
        return curr_max

    def longestWPI(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        tiring_or_not_list = []
        self.createTiringDaList(hours, tiring_or_not_list)
        return self.findMaxWPI(tiring_or_not_list)
            

        