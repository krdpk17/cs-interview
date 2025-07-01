# Need optimization. 129/132 test failed with timeout
# https://leetcode.com/problems/palindromic-substrings/description/?envType=problem-list-v2&envId=oizxjoit
class Solution:
    def check_palindrome(self, s, s_index, e_index):
        while(s_index < e_index):
            if(s[s_index] != s[e_index]):
                return False
            s_index += 1
            e_index -= 1
            
        return True

    def palindrome_starting_with(self, s, index, dict_map):
        size = len(s)
        i = index
        substr = ""
        substr += s[i]
        dict_map.append(substr)
        j = i + 1
        while(j < size):
            if(s[j] != s[i]):
                j += 1
                continue
            if(self.check_palindrome(s, i, j) == True):
                substr = s[i:j]
                dict_map.append(substr)
            j += 1
            
        return dict_map
        

    def countSubstrings(self, s: str) -> int:
        dict_map = []
        i = 0
        size = len(s)
        for i in range(size):
            self.palindrome_starting_with(s,i, dict_map)
        print(dict_map, len(dict_map))
        return len(dict_map)
        
