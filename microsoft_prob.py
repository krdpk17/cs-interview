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

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
def add_entry(count_map, char):
    if(char not in count_map):
        count_map[char] = 0
    count_map[char] += 1

def gather_counts(P, Q, char_matched_count, char_total_count, char_unmatched_count):
    #create map of matched and total
    str_len = len(P)
    for index in range(0, str_len):
        char_p = P[index]
        char_q = Q[index]
        if(char_p == char_q):
            add_entry(char_matched_count, char_p)
            add_entry(char_total_count, char_p)
        else:
            add_entry(char_total_count, char_p)
            add_entry(char_total_count, char_q)

    #create map of unmatched count
    for char, count in char_total_count.items():
        count = char_total_count[char]
        if char in char_matched_count:
            count -= 1
        char_unmatched_count[char] = count

#created sorted list in descreasing order
def insert_in_sorted_list(sorted_count, char, count):
    list_len = len(sorted_count)
    index_to_add = -1
    for index in range(0, list_len):
        if(count > sorted_count[index][1]):
            index_to_add = index
            break
    if(index_to_add == -1):
        index_to_add = list_len
    #print(index_to_add),
    sorted_count.insert(index_to_add, [char, count])
    

def sort_count(char_count, sorted_count):
    #sorted_count = []
    for char, count in char_count.items():
        insert_in_sorted_list(sorted_count, char, count)


def exclude_highest_occuring_char(sorted_unmatched_count, P, Q, char_unmatched_count, char_matched_count, new_p, new_q):
    total_len = len(P)
    rem_len = total_len
    curr_max = sorted_unmatched_count[0]
    rem_len = total_len - curr_max[1]
    #print(rem_len)
    new_p = ''
    new_q = ''
    for index in range(0, total_len):
        #form new string without the max string
        if(P[index] != curr_max[0]) and (Q[index] != curr_max[0]): 
            new_p +=P[index]
            new_q +=Q[index]
        elif P[index] == curr_max[0] and Q[index] == curr_max[0]: # both has same char
            char_matched_count[P[index]] -= 1
        else:
            #reduce from the count map as it is used
            char_unmatched_count[P[index]] -= 1
            char_unmatched_count[Q[index]] -= 1
    return

def calculate_min_string(sorted_unmatched_count, P, Q, char_unmatched_count, char_matched_count):
    new_p = ''
    new_q = ''
    count = 0
    p = P
    q = Q
    count += 1
    exclude_highest_occuring_char(sorted_unmatched_count, p, q, char_unmatched_count, char_matched_count, new_p, new_q)
    while(len(new_p) > 0):
        p = new_p
        q = new_q
        sorted_unmatched_count = sorted_unmatched_count[1:]
        count += 1
        exclude_highest_occuring_char(sorted_unmatched_count, p, q, char_unmatched_count, char_matched_count, new_p, new_q)
        #count += 1

    return count
   


    
    

def solution(P, Q):
    # Implement your solution here

    char_matched_count = {}
    char_total_count = {}
    char_unmatched_count = {}
    
    '''
    Create hash map of all characters
    One map keeps count of matched char
    Other map keeps total count of each char
    '''
    gather_counts(P, Q, char_matched_count, char_total_count, char_unmatched_count)
    print(char_matched_count)
    print(char_total_count)
    print(char_unmatched_count)
    
    #sort unmatched count
    sorted_unmatched_count = []
    sort_count(char_unmatched_count, sorted_unmatched_count)
    min_len = calculate_min_string(sorted_unmatched_count, P, Q, char_unmatched_count, char_matched_count)
    print(sorted_unmatched_count)
    print(min_len)
    return min_len
    pass
