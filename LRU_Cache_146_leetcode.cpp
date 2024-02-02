#include<list>
#include<map>
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        int val = -1;
        if(m_key_val.find(key) != m_key_val.end()){
            val = m_key_val[key];
            //adjust the key position in LRU
            m_lru.remove(key);
            m_lru.push_front(key);

        }

        
        return val;
    }
    
    void put(int key, int value) {
        if(m_key_val.find(key) != m_key_val.end()){
            // update the key info and LRU status
            m_key_val[key] = value;
            m_lru.remove(key);
            m_lru.push_front(key);
            return;
        }
        int key_to_be_removed = 0;
        //printf("LRU size is %d", m_lru.size());
        // need to add new entry
        if(m_lru.size() >= m_capacity){//need to create space
            //Remove last entry in the queue
            key_to_be_removed = m_lru.back();
            //cout<<"key is"<<key_to_be_removed<<" ";
            m_key_val.erase(key_to_be_removed);
            m_lru.remove(key_to_be_removed);
        }
        m_lru.push_front(key);
        m_key_val[key] = value;
        return;
    }
    list<int> m_lru;
    map<int, int> m_key_val;
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */