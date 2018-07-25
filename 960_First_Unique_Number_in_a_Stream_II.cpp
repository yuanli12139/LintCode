/*
960. First Unique Number in a Stream II
We need to implement a data structure named DataStream. There are two methods required to be implemented:

void add(number) // add a new number
int firstUnique() // return first unique number

Example
add(1)
add(2)
firstUnique() => 1
add(1)
firstUnique() => 2


Author: Yuan Li
Date: 7/24/2018 
Difficulty: Medium
*/

class DataStream {
public:
    
    DataStream() {
        // do intialization if necessary
        head = new LinkedNode();
        tail = head;
    }
    
    // a linked list containing unique numbers in order
    class LinkedNode {
    public:
        int val;
        LinkedNode* next;
        
        // constructor
        LinkedNode(int val = 0) {
            this->val = val;
            next = nullptr;
        }
    };
    
    /**
     * @param num: next number in stream
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        // never let duplicates in linked list
        if (duplicates.count(num)) { 
            return;
        }
        
        // num is/isn't already in linked list
        if (val2prev.count(num)) {
            erase(num);
            duplicates.insert(num); // record duplicates
        } else { 
            val2prev[num] = tail;
            
            LinkedNode* new_node = new LinkedNode(num);
            tail->next = new_node;
            tail = new_node;
        }
    }

    /**
     * @return: the first unique number in stream
     */
    int firstUnique() {
        // write your code here
        return head->next->val;
    }
    
    // head -> ... -> prev -> node -> next -> ... -> tail
    //                        v               
    // head -> ... -> prev -> next -> ... -> tail
    void erase(int num) {
        LinkedNode* prev = val2prev[num];
        if (prev->next == tail) {
            tail = prev;
        } else {
            prev->next = prev->next->next;
            val2prev[prev->next->val] = prev;
        }
        
        val2prev.erase(num);
    }
    
private:
    LinkedNode* head;
    LinkedNode* tail;
    unordered_map<int, LinkedNode*> val2prev;
    unordered_set<int> duplicates;
};
