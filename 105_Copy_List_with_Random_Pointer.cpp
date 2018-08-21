/*
105. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Challenge
Could you solve it with O(1) space?


Author: Yuan Li
Date: 8/20/2018 
Difficulty: Medium
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (head == nullptr) {
            return nullptr;
        }
        
        unordered_map<RandomListNode*, RandomListNode*> node_newNode;
        
        RandomListNode *dummy = new RandomListNode();
        RandomListNode *pre = dummy, *newNode;
        
        while (head) {
            if (node_newNode.count(head)) {
                newNode = node_newNode[head];
            } else {
                newNode = new RandomListNode(head->label);
                node_newNode[head] = newNode;
            }
            
            if (head->random) {
                if (node_newNode.count(head->random)) {
                    newNode->random = node_newNode[head->random];
                } else {
                    newNode->random = new RandomListNode(head->random->label);
                }
            }
            
            pre->next = newNode;
            pre = newNode;
            head = head->next;
        }
        
        return dummy->next;
    }
};
