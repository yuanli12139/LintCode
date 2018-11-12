/*
24. LFU Cache
LFU (Least Frequently Used) is a famous cache eviction algorithm.

For a cache with capacity k, if the cache is full and need to evict a key in it, the key with the lease frequently used will be kicked out.

Implement set and get method for LFU cache.

Example
Given capacity=3

set(2,2)
set(1,1)
get(2)
>> 2
get(1)
>> 1
get(2)
>> 2
set(3,3)
set(4,4)
get(3)
>> -1
get(2)
>> 2
get(1)
>> 1
get(4)
>> 4


Author: Yuan Li
Date: 11/11/2018 
Difficulty: Hard
*/

// set: O(log(n)) 
// get: O(log(n))
class LFUCache {
  public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity) {
        // do intialization if necessary
        capacity_ = capacity;
        tick_ = 0;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (capacity_ == 0) {
            return;
        }
        
        auto it = kn_.find(key);
        
        // key exists, simply update val, freq and tick
        if (it != kn_.cend()) {
            it->second.val = value;
            update(it->second);
            return;
        }
            
        // key doesn't exists, remove a least frequent node
        if (kn_.size() == capacity_) {
            const Node& node = *cache_.cbegin();
            kn_.erase(node.key);
            cache_.erase(node);
        }
        
        // add new node
        Node node{key, value, 1, ++tick_};
        kn_[node.key] = node;
        cache_.insert(node);
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        auto it = kn_.find(key);
        if (it == kn_.cend()) {
            return -1;
        }
        update(it->second);
        return it->second.val;
    }
    
  private:
    struct Node {
        int key;
        int val;
        int freq;
        long tick;
        
        bool operator<(const Node &rhs) const {
            if (freq == rhs.freq) {
                return tick < rhs.tick;
            }
            return freq < rhs.freq;
        }
    };
    
    int capacity_;
    long tick_;
    unordered_map<int, Node> kn_; // key -> node
    std::set<Node> cache_;
    
  private:
    void update(Node &node) {
        // erase -> insert <=> reorder the balanced search tree
        cache_.erase(node);
        ++node.freq;
        node.tick = ++tick_;
        cache_.insert(node);
    }
};

