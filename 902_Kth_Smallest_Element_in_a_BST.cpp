/*
902. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example
Given root = {1,#,2}, k = 2, return 2.

Challenge
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Notice
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.


Author: Yuan Li
Date: 9/6/2018 
Difficulty: Medium
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
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        int res;
        int cnt = 0;
        
        while (root) {
            stk_.push(root);
            root = root->left;
        }
        
        while (!stk_.empty()) {
            TreeNode* node = stk_.top();
            ++cnt;
            if (cnt == k) {
                res = node->val;
                break;
            }
            
            if (node->right) { // look for the left-most of right subtree
                node = node->right;
                while (node) {
                    stk_.push(node);
                    node = node->left;
                }
            } else { // look for the first left turn
                stk_.pop();
                while (!stk_.empty() && stk_.top()->right == node) {
                    node = stk_.top();
                    stk_.pop();
                }
            }
        }
        
        return res;
    }
    
  private:
    stack<TreeNode*> stk_;
};
