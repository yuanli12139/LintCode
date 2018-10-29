/*
661. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example
Given a binary search Tree `{5,2,13}｀:

              5
            /   \
           2     13
Return the root of new tree

             18
            /   \
          20     13


Author: Yuan Li
Date: 10/28/2018 
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
     * @param root: the root of binary tree
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
        // write your code here
        dfs(root);
        return root;
    }
    
  private:
    int sum_ = 0;
    
  private:
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        
        dfs(node->right);
        
        sum_ += node->val;
        node->val = sum_;
        
        dfs(node->left);
    }
};

