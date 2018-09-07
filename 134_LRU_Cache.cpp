/*
134. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.


Author: Yuan Li
Date: 7/23/2018 
Difficulty: Hard
*/

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
            LinkedNode* new_node = new LinkedNode(key, value);
            push_back(new_node);
            // push_back(new LinkedNode(key, value)); // potentially bad practice as new can't be deleted
            
            if (hash.size() > capacity) {
                pop_front();
            }
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
        hash[head->next->key] = head;
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
