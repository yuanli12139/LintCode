/*
69. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Challenge
Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use DFS algorithm to do it.


Author: Yuan Li
Date: 7/4/2018 
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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        
        if (root == nullptr) 
            return res;
            
        queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        
        while (!treeQueue.empty()) {
            vector<int> level;
            
            int size = treeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode * currNode = treeQueue.front();
                treeQueue.pop();
                
                level.push_back(currNode->val);
                
                if (currNode->left) {
                    treeQueue.push(currNode->left);
                }
                
                if (currNode->right) {
                    treeQueue.push(currNode->right);
                }
            }
            
            res.push_back(level);
        }
        
        return res;
    }
};
