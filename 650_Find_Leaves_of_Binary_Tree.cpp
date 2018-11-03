/*
650. Find Leaves of Binary Tree
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example
Given binary tree:

    1
   / \
  2   3
 / \     
4   5    
Returns [[4, 5, 3], [2], [1]].


Author: Yuan Li
Date: 11/2/2018 
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
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        
        int max_depth = dfs(root);
        for (int i = 1; i <= max_depth; ++i) {
            res.push_back(depth_vals_[i]);
        }
        
        return res;
    }
    
  private:
    unordered_map<int, vector<int>> depth_vals_;

  private:
    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        int depth = max(dfs(node->left), dfs(node->right)) + 1;
        depth_vals_[depth].push_back(node->val);
        
        return depth;
    }
};

