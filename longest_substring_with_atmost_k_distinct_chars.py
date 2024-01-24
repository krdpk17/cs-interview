'''
Given a string you need to print the size of the longest possible substring that has atmost K unique characters. If there is no possible substring then print -1.
Leetcode reference https://leetcode.ca/all/340.html
'''
class MaxSub:
    def __init__(self, start_index, end_index):
        self.start_index = start_index
        self.end_index = end_index
        self.len = end_index - start_index + 1

def longest_substr_with_k_distinct_chars(in_str, k):
    chars_found = {}
    curr_index = 0
    start_index = 0
    curr_max = MaxSub(start_index=-1,end_index=-1)
    while(curr_index < len(in_str)):
        # for each char, check if it is still worth to add
        curr_char = in_str[curr_index]
        if(curr_char  in chars_found):
            #add curr char in the substring list and move for next
            chars_found[curr_char] += 1
            curr_index += 1
            continue
        if(curr_char not in chars_found):
            #check if new char adding satisfy the condition (k distinct chars)
            if(len(chars_found) < k):
                # satisfy condition and so add it
                chars_found[curr_char] = 1
            else:
                #need to look for new substring
                curr_len = curr_index - start_index
                if(curr_len > curr_max.len):
                    curr_max = MaxSub(start_index=start_index, end_index=curr_index-1) #store curr max
                while( curr_index < len(in_str) ):
                    #move start pointer until space comes or end of string reaches
                    start_char = in_str[start_index]
                    chars_found[start_char] -= 1
                    if(chars_found[start_char] == 0):
                        #add new char
                        chars_found.pop(start_char)
                        chars_found[curr_char] = 1
                        start_index += 1
                        break
                    start_index += 1
            curr_index += 1 #move to next char
    #finally adjust the max substring
    curr_len = curr_index - start_index
    if(curr_len > curr_max.len):
        curr_max = MaxSub(start_index=start_index, end_index=curr_index-1) #store curr max                 
    return curr_max

if(__name__ == "__main__"):
    in_strs = ["aabacbebebe", "aaaa", "eceba"]
    k = 2
    for in_str in in_strs:
        res = longest_substr_with_k_distinct_chars(in_str=in_str, k=k)
        print("string="+ in_str, " k= "+str(k), " substr len="+str(res.len), " start="+str(res.start_index), " end="+ str(res.end_index) )

