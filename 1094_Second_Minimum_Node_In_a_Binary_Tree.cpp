/*
1094. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example
Example 1:

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.


Author: Yuan Li
Date: 9/5/2018 
Difficulty: Easy
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
  public:
    /**
     * @param root: the root
     * @return: the second minimum value in the set made of all the nodes' value in the whole tree
     */
    int findSecondMinimumValue(TreeNode * root) {
        // Write your code here
        if (root == nullptr || root->left == nullptr) { // root->left == nullptr <=> root->right == nullptr
            return -1;
        }
        
        TreeNode* smaller_sub = (root->val == root->left->val) ? root->left : root->right;
        TreeNode* larger_sub = (root->val == root->left->val) ? root->right : root->left;
        
        if (smaller_sub->val == larger_sub->val) {
            int s = findSecondMinimumValue(smaller_sub);
            int l = findSecondMinimumValue(larger_sub);
            
            if (s == -1) {
                return l;
            }
            
            if (l == -1) {
                return s;
            }
            
            return s < l ? s : l;
        }
        
        int s = findSecondMinimumValue(smaller_sub);
        
        return (s != -1 && s < larger_sub->val) ? s : larger_sub->val;
    }
};
