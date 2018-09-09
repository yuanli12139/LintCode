/*
134. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.


Author: Yuan Li
Date: 7/23/2018 
Difficulty: Hard
*/

// singly linked list
class LRUCache {
  public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        // do intialization if necessary
        this->capacity = capacity;
        head = new LinkedNode();
        tail = head;
    }

    // // nested class
    // class LinkedNode {
    // public:
    //     int key; 
    //     int value;
    //     LinkedNode* next;
        
    //     // constructor
    //     LinkedNode(int key = 0, int value = 0) {
    //         this->key = key;
    //         this->value = value;
    //         next = nullptr;
    //     }
    // };

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if (hash.count(key)) {
            move_back(hash[key]);
            return hash[key]->next->value;
        }
        
        return -1;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (hash.count(key)) {
            move_back(hash[key]);
            hash[key]->next->value = value;
        } else {
            if (hash.size() == capacity) {
                pop_front();
            }
            
            LinkedNode* new_node = new LinkedNode(key, value);
            push_back(new_node);
            // push_back(new LinkedNode(key, value)); // potentially bad practice as new can't be deleted
        }
    }
    
  private:
    class LinkedNode {
    public:
        int key; 
        int value;
        LinkedNode* next;
        
        // constructor
        LinkedNode(int key = 0, int value = 0) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
    };
  
    int capacity;
    unordered_map<int, LinkedNode*> hash; // key -> pointer to its previous node
    LinkedNode* head;
    LinkedNode* tail;
    
  private:
    void pop_front() {
        hash.erase(head->next->key);
        head->next = head->next->next;
        if (head->next) { // for capacity == 1
            hash[head->next->key] = head;
        }
    }
    
    void push_back(LinkedNode* node) {
        hash[node->key] = tail;
        tail->next = node;
        tail = node;
    }
    
    // prev -> node -> next -> ... -> tail =>
    // prev -> next -> ... -> tail = node
    void move_back(LinkedNode* prev) {
        LinkedNode* node = prev->next;
        if (node == tail) {
            return;
        }

        prev->next = node->next; 
        hash[node->next->key] = prev;
        
        node->next = nullptr; 
        push_back(node);
    }
};


/*
Reference
https://zxi.mytechroad.com/blog/hashtable/leetcode-146-lru-cache/

Date: 9/6/2018
*/

// doubly linked list
#include <list>

class LRUCache {
  public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        // do intialization if necessary
        capacity_ = capacity;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        const auto mit = m_.find(key);
        if (mit == m_.end()) {
            return -1;
        }
        
        // key exists
        cache_.splice(cache_.begin(), cache_, mit->second);
        return mit->second->second;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        const auto mit = m_.find(key);
        if (mit != m_.end()) { // key exists
            mit->second->second = value;
            cache_.splice(cache_.begin(), cache_, mit->second);
            return;
        }
        
        // key doesn't exist, check capacity first
        if (m_.size() == capacity_) {
            const auto &node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }
        
        // add new node to the front
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
    
  private:
    int capacity_;
    list<pair<int, int>> cache_; // {key, value} <-> {key, value} <-> ...
    unordered_map<int, list<pair<int, int>>::iterator> m_; // key -> iterator of node
};
