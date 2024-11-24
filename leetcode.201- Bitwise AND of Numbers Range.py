'''
Time Limit Exceeded
8265 / 8271 testcases passed
'''

class Solution:
    def get_closet_successor_multiple(self, multiple, val):
        prev_val = next_val = multiple
        if(multiple == 1):
            return val + 1
        while(next_val <= val):
            prev_val = next_val
            next_val = next_val + multiple
        return next_val
    def reverse_num(self, num, count):
        index = 1
        res = 0
        while(index <= count):
            val = num & 1
            res = res << 1
            res = res | val
            num = num >> 1
            count = count - 1
        return res

    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        temp = left
        result = 0
        jump = 1
        count = 0
        while(temp):
            count = count + 1
            rightmostbit = temp & 1
            bit_val = 0
            #next_val = jump
            if(rightmostbit):
                closet_successor = self.get_closet_successor_multiple(jump, left)
                print(jump, rightmostbit, temp, '-', jump, closet_successor)
                if(closet_successor <= right):
                    bit_val = 0
                else:
                    bit_val = 1
            result = result << 1 
            result = result | bit_val
            temp = temp >> 1
            jump = jump << 1
        print(result)
        result = self.reverse_num(result, count)
        print(result)
        return result
