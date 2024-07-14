/**
 * This code is working but having time-out issue
 * So, it means that code is not optimal
 * https://leetcode.com/problems/longest-string-chain/ 
*/

class Solution {
public:
    static bool compare(string &str1, string &str2){
        return str1.size() < str2.size();
    }

    bool checkPredecessor(string &word1, string &word2){
        int len1 = word1.size();
        int len2 = word2.size();
        int diff_count = 0;
        int i;
        int j;
        //cout<<diff_count<<" "<<word1<<" "<<word2<<endl;
        string new_word;
        for(i = 0, j=0; i < len1; ++i, ++j){
            if(word1[i] == word2[j]){
                new_word.push_back(word1[i]);
            }else{
                break;
            }
        }
        new_word.push_back(word2[j]);
        ++j;
        while(i < len1){
            new_word.push_back(word1[i]);
            ++i;
        }
        if(new_word == word2){
            return true;
        }else{
            return false;
        }
    }

struct node{
    string m_str;
    vector<node *> children;
    node(string str){
        m_str = str;
    }
};

    void buildWordMap(vector<string>& words, map<int, vector<string>>& words_len_map){
        int size = words.size();
        for(int i = 0; i < size; ++i){
            int len = words[i].size();
            if(words_len_map.find(len) == words_len_map.end()){
                vector<string> empty_vector;
                words_len_map[len] = empty_vector;
            }
            words_len_map[len].push_back(words[i]);
        }

    }

    node * buildChainMap(vector<string>& words){
        int min_str_len = words[0].size();
        int max_str_len = words[words.size() - 1].size();
        int curr_str_len = min_str_len;
        node *root = new node("");
        int i;
        map<int, vector<string>> words_len_map;
        buildWordMap(words, words_len_map);
        vector<node *> node_queue;

        for(i = 0; i < words.size(); ++i){//add all strings as root .. will help to find all chain
            node *temp = new node(words[i]);
            (root->children).push_back(temp);
            node_queue.push_back(temp);
        }

        while(!node_queue.empty()){
            node *curr_node = node_queue.front();
            string curr_str = curr_node->m_str;
            int len = curr_str.size();
            node_queue.erase(std::remove(node_queue.begin(), node_queue.end(), curr_node), node_queue.end());
            if(words_len_map.find(len+1) != words_len_map.end()){
                vector<string> candidate_strings = words_len_map[len+1];
                for(int i = 0; i < candidate_strings.size(); ++i){
                    if(checkPredecessor(curr_str, candidate_strings[i]) == true){
                        node *temp = new node(candidate_strings[i]);
                        (curr_node->children).push_back(temp);
                        node_queue.push_back(temp);
                    }
                }
            }//if
        }
        return root;
    }

    int printTree(node *root){
        vector<node *> node_queue;
        node_queue.push_back(root);
        node_queue.push_back(NULL);//level marker
        int curr_level = -1;
        while(!node_queue.empty()){
            node *curr_node = node_queue.front();
            node_queue.erase(std::remove(node_queue.begin(), node_queue.end(), curr_node), node_queue.end());
            if(curr_node == NULL){
                ++curr_level;
                //cout<<endl;
                if(!node_queue.empty()){
                    node_queue.push_back(NULL);
                }
                continue;
            }
            //cout<<" "<<curr_node->m_str;
            vector<node *>& children = curr_node->children;
            for(int i = 0; i < children.size(); ++i){//add all children in queue
                node_queue.push_back(children[i]);
            }
        }
        return curr_level;
    }

    int longestStrChain(vector<string>& words) {
        int len = -1;
        if(words.size() == 1){
            return 1;
        }
        sort(words.begin(), words.end(), Solution::compare);
        //map<string, vector<string>> chain_map;
        node *root = buildChainMap(words);
        len = printTree(root);
        //print_chain_map(chain_map);
        //len = getMaxLenChain(chain_map);
        return len;
    }
};