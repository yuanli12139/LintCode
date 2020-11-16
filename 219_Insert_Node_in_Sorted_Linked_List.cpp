/*
219. Insert Node in Sorted Linked List
Insert a node in a sorted linked list.

Example
Given list = 1->4->6->8 and val = 5.

Return 1->4->5->6->8.


Author: Yuan Li
Date: 10/30/2018 
Difficulty: Easy
*/

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param val: An integer.
     * @return: The head of new linked list.
     */
    ListNode * insertNode(ListNode * head, int val) {
        // write your code here
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (prev->next != nullptr && prev->next->val < val) {
            prev = prev->next;
        }
        
        ListNode* node = new ListNode(val);
        node->next = prev->next;
        prev->next = node;
        
        return dummy->next;
    }
};

