/*
104. Merge K Sorted Lists
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Example
Given lists:

[
  2->4->null,
  null,
  -1->null
],
return -1->2->4->null.


Author: Yuan Li
Date: 7/25/2018 
Difficulty: Medium
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 
// priority queue - O(nlogK)
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.size() == 0) {
            return nullptr;
        }
        
        // lambda expression
        auto comp = [](const auto &lhs, const auto &rhs) -> bool {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // for (ListNode*& list : lists) {
        for (auto &list : lists) {
            if (list) {
                pq.push(list);
            }
        }               
        
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            ListNode* new_node = new ListNode(node->val);
            tail->next = new_node;
            tail = new_node;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy->next;
    }
};


// merge two by two - O(nlogK)
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.empty()) {
            return nullptr;
        }
        
        while (lists.size() > 1) {
            vector<ListNode*> new_lists;
            for (int i = 0; i + 1 < lists.size(); i += 2) {
                ListNode* new_list = merge2Lists(lists[i], lists[i+1]);
                new_lists.push_back(new_list);
            }
            
            if (lists.size() % 2 == 1) {
                new_lists.push_back(lists.back());
            }
            
            lists = new_lists;
        }
        
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            
            tail = tail->next;
        }
        
        // while (l1) {
        //     tail->next = l1;
        //     tail = l1;
        //     l1 = l1->next;
        // }
        
        // while (l2) {
        //     tail->next = l2;
        //     tail = l2;
        //     l2 = l2->next;
        // }
        
        // no need to update tail
        if (l1) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        return dummy->next;
    }
};


// divide & conquer
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.empty()) {
            return nullptr;
        }
        
        return merge(lists, 0, lists.size() - 1);
    }
    
    ListNode* merge(vector<ListNode*> &lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        
        int mid = start + (end - start) / 2;
        ListNode* left = merge(lists, start, mid);
        ListNode* right = merge(lists, mid + 1, end);
        
        return merge2Lists(left, right);
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            
            tail = tail->next;
        }
        
        if (l1) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        
        return dummy->next;
    }
};
