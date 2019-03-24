/*
167. Add Two Numbers

You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Example
Example 1:
	Input: 7->1->6->null, 5->9->2->null
	Output: 2->1->9->null
	
	Explanation:
	617 + 295 = 912
	912 to list:  2->1->9->null


Example 2:
	Input:  3->1->5->null, 5->9->2->null
	Output: 8->0->8->null
	
	Explanation: 
	513 + 295 = 808
	808 to list: 8->0->8->null


Author: Yuan Li
Date: 3/23/2019 
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        int carry = 0;
        for (ListNode *i = l1, *j = l2; i || j; ) {
            int sum = carry;
            sum += i ? i->val : 0;
            sum += j ? j->val : 0;
            
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            
            carry = sum / 10;
            
            i = i ? i->next : i;
            j = j ? j->next : j;
        }
        
        if (carry) {
            tail->next = new ListNode(carry);
        }
        
        return dummy->next;
    }
};

