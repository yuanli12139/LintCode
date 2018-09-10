/*
1245. All O`one Data Structure
Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".

Challenge
Perform all these in O(1) time complexity.

Reference
https://zxi.mytechroad.com/blog/data-structure/leetcode-432-all-oone-data-structure/


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Hard
*/

#include <list>

class AllOne {
  public:
    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto mit = m_.find(key);
        if (mit == m_.end()) {
            if (l_.empty() || l_.front().val > 1) { // need to create a new node
                l_.push_front({1, {key}});
            } else {
                l_.front().keys.insert(key);
            }
            
            m_[key] = l_.begin();
            return;
        }
        
        auto lit = mit->second;
        auto nlit = next(lit);
        if (nlit == l_.end() || lit->val + 1 < nlit->val) { // need to create a new node
            nlit = l_.insert(nlit, {lit->val + 1, {}});
        }
        nlit->keys.insert(key);
        
        m_[key] = nlit;
        
        // update current node after key is removed
        deleteKey(lit, key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto mit = m_.find(key);
        if (mit == m_.end()) {
            return;
        }
        
        auto lit = mit->second;
        if (lit->val > 1) {
            auto plit = prev(lit);
            
            if (lit == l_.begin() || lit->val - 1 > plit->val) { // need to create a new node
                plit = l_.insert(lit, {lit->val - 1, {}});
            }
            plit->keys.insert(key);
            
            m_[key] = plit;
        } else {
            m_.erase(key);
        }
        
        // update current node after key is removed
        deleteKey(lit, key);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return l_.empty() ? "" : *(l_.back().keys.cbegin());
    }
    
    /** Returns one of the keys with minimal value. */
    string getMinKey() {
        return l_.empty() ? "" : *(l_.front().keys.cbegin());
    }
    
  private:
    struct Node {
        int val;
        unordered_set<string> keys;
    };
    
    list<Node> l_;
    unordered_map<string, list<Node>::iterator> m_;
    
  private:
    void deleteKey(list<Node>::iterator lit, const string &key) {
        lit->keys.erase(key);
        if (lit->keys.empty()) {
            l_.erase(lit);
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
