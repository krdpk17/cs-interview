# Code works but its suboptimal. Memoization is not helpin
class Solution(object):
    def is_successor(self, pre_word, next_word):
        pre_word_size = len(pre_word)
        next_word_size = len(next_word)
        i = 0
        j = 0
        if(pre_word_size != next_word_size - 1):
            return False

        diff_buffer = 1
        while(i < pre_word_size):
            if(pre_word[i] != next_word[j]):
                j = j + 1
                if(diff_buffer == 0):
                    return False
                diff_buffer = diff_buffer - 1
            else:
                i = i + 1
                j = j + 1

        return True


    def find_longest_chain_old(self, words, start_i, selected_words):
        if(start_i >= len(words)):
            return selected_words
        selected_words_copy = list(selected_words)
        selected_words_with = []
        if(len(selected_words)== 0):
            selected_words_copy.append(words[start_i])
            selected_words_with = self.find_longest_chain(words, start_i + 1, selected_words_copy)
        elif(self.is_successor(selected_words[-1], words[start_i]) == True):
            selected_words_copy.append(words[start_i])
            selected_words_with = self.find_longest_chain(words, start_i + 1, selected_words_copy)

        selected_words_copy2 = list(selected_words)
        selected_words_without = self.find_longest_chain(words, start_i + 1, selected_words_copy2)

        len_selected_words_with = len(selected_words_with)
        len_selected_words_without = len(selected_words_without)
        if(len_selected_words_with > len_selected_words_without):
            return selected_words_with
        else:
            return selected_words_without


    def find_longest_chain(self, words, start_i, selected_last_word, selected_len, dp):
        if(start_i >= len(words)):
            return selected_len
        key = (start_i, selected_last_word)
        if key in dp:
            return dp[key]
        selected_words_copy = selected_last_word
        len_selected_words_with = None
        if(selected_last_word == None):
            selected_words_copy = words[start_i]
            #print(selected_words_copy)
            key = (start_i + 1, selected_words_copy)
            if key in dp:
                len_selected_words_with =  dp[key]
            else:
                len_selected_words_with = self.find_longest_chain(words, start_i + 1, selected_words_copy, selected_len + 1, dp)
        elif(self.is_successor(selected_last_word, words[start_i]) == True):
            selected_words_copy = words[start_i]
            key = (start_i + 1, selected_words_copy)
            if key in dp:
                len_selected_words_with =  dp[key]
            else:
                len_selected_words_with = self.find_longest_chain(words, start_i + 1, selected_words_copy, selected_len + 1, dp)

        selected_words_copy2 = selected_last_word
        key = (start_i + 1, selected_words_copy2)
        if key in dp:
            len_selected_words_without =  dp[key]
        else:
            len_selected_words_without = self.find_longest_chain(words, start_i + 1, selected_words_copy2, selected_len, dp)

        #print(selected_words_copy, selected_words_copy2, len_selected_words_with, len_selected_words_without)
        if(len_selected_words_with > len_selected_words_without):
            dp[(start_i, selected_last_word)] = len_selected_words_with
        else:
            dp[(start_i, selected_last_word)] = len_selected_words_without
        
        return dp[(start_i, selected_last_word)] 



    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        print (words)
        sorted_words = sorted(words, key=len)
        print(sorted_words)
        selected_last_word = None

        dp = {}
        selected_words_max = self.find_longest_chain(sorted_words, 0, selected_last_word, 0, dp)
        return selected_words_max
        
