/*
228. Middle of Linked List
Find the middle node of a linked list.

Example
Given 1->2->3, return the node with value 2.

Given 1->2, return the node with value 1.

Challenge
If the linked list is in a data stream, can you find the middle without iterating the linked list again?


Author: Yuan Li
Date: 6/26/2018 
Difficulty: Naive
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


class Solution {
public:
    /*
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        // write your code here
        ListNode *slow = head, *fast = head;
        while (slow != nullptr && fast != nullptr) {
            if (fast->next == nullptr)
                break;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
