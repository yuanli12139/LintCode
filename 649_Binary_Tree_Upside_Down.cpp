/*
649. Binary Tree Upside Down
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

Example
Given a binary tree {1,2,3,4,5}

    1
   / \
  2   3
 / \
4   5
return the root of the binary tree {4,5,2,#,#,3,1}.

   4
  / \
 5   2
    / \
   3   1  


Author: Yuan Li
Date: 10/31/2018 
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
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        // write your code here
        if (root == nullptr) {
            return root;
        }
        return dfs(root);
    }
    
  private:
    TreeNode* dfs(TreeNode* node) {
        if (node->left == nullptr) {
            return node;
        }
        
        TreeNode* new_root = dfs(node->left); // go left
        
        node->left->left = node->right;
        node->left->right = node;
        
        node->left = nullptr;
        node->right = nullptr;
        
        return new_root;
    }
};

