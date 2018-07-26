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
 
 // priority queue
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
        
        ListNode* head = new ListNode();
        ListNode* tail = head;
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
        
        return head->next;
    }
};
