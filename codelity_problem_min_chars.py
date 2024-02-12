'''
We are given two strings P and Q, each consisting of N lowercase English letters. For each position in the strings, we have to choose one letter from either P or Q, in order to construct a new string S, such that the number of distinct letters in S is minimal. Our task is to find the number of distinct letters in the resulting string S.

For example, if P = "ca" and Q = "ab", S can be equal to: "ca", "cb", "aa" or "ab". String "aa" has only one distinct letter ('a'), so the answer is 1 (which is minimal among those strings).
Write a function:
def solution(P, Q)
that, given two strings P and Q, both of length N, returns the minimum number of distinct letters of a string S, that can be constructed from P and Q as described above.
Examples:
1. Given P = "abc", Q = "bcd", your function should return 2. All possible strings S that can be constructed are: "abc", "abd", "acc", "acd", "bbc", "bbd", "bcc", "bcd". The minimum number of distinct letters is 2, which be obtained by constructing the following strings: "acc", "bbc", "bbd", "bcc".
2. Given P = "axxz", Q = "yzwy", your function should return 2. String S must consist of at least two distinct letters in this case. We can construct S = "yxxy", where the number of distinct letters is equal to 2, and this is the only optimal solution.
3. Given P = "bacad", Q = "abada", your function should return 1. We can choose the letter 'a' in each position, so S can be equal to "aaaaa".
4. Given P = "amz", Q = "amz", your function should return 3. The input strings are identical, so the only possible S that can be constructed is "amz", and its number of distinct letters is 3.
Write an efficient algorithm for the following assumptions:
* N is an integer within the range [1..200,000];
* strings P and Q are both of length N;
* strings P and Q are made only of lowercase letters (a−z);
* strings P and Q contain a total of at most 20 distinct letters.

'''

#adds character info to the map
def add_entry(count_map, char):
    if(char not in count_map):
        count_map[char] = 0
    count_map[char] += 1

#util for counting number of occurance for each char
#if both P and Q has char at same position, then count is incremented only once, not twice
def gather_counts(P, Q, char_total_count):
    #create map of matched and total
    str_len = len(P)
    for index in range(0, str_len):
        char_p = P[index]
        char_q = Q[index]
        if(char_p == char_q):
            add_entry(char_total_count, char_p)
        else:
            add_entry(char_total_count, char_p)
            add_entry(char_total_count, char_q)


'''
For each position, exclude the count of less occuring charater
'''
def calculate_min_string(char_total_count, P, Q):
    #distinct_chars = set(P) | set(Q)
    str_len = len(P)

    for i in range(str_len):
        if(P[i] != Q[i]):
            if(char_total_count[P[i]] < char_total_count[Q[i]]): #less frequent is not needed
                char_total_count[P[i]]  -= 1
            else:
                char_total_count[Q[i]]  -= 1
    
    min_distinct_chars = []
    for char, count in char_total_count.items():
        if count > 0:
            min_distinct_chars.append(char)
    return len(min_distinct_chars)

 
def solution(P, Q):
    # Implement your solution here

    char_total_count = {}
    
    '''
    Create hash map of all characters
    One map keeps count of matched char
    Other map keeps total count of each char
    '''
    gather_counts(P, Q, char_total_count)
    #print(char_matched_count)
    #print(char_total_count)
    #print(char_unmatched_count)
    
    min_len = calculate_min_string(char_total_count, P, Q)
    #print(min_len)
    return min_len

if(__name__ == "__main__"):
    print(solution("abc", "bcd"))
    print(solution("axxz", "yzwy"))
    print(solution("bacad", "abada"))
    print(solution("amz", "amz"))