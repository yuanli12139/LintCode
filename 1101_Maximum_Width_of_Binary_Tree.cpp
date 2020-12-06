/*
1101. Maximum Width of Binary Tree
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example
Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,#,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
        
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,#,#,#,#,#,#,7).
Notice
The answer will be in the range of 32-bit signed integer.


Author: Yuan Li
Date: 12/6/2020
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
     * @param root: the root
     * @return: the maximum width of the given tree
     */
    int widthOfBinaryTree(TreeNode * root) {
        // Write your code here
        if (!root) {
            return 0;
        }
        
        dfs(root, 0, 1);
        return max_width_;
    }
    
private:
    int max_width_ = 1;
    unordered_map<int, int> depth_2_lmost_;

private:
    void dfs(TreeNode * node, int depth, int idx) {
        if (!node) {
            return;
        }
        
        dfs(node->left, depth + 1, idx * 2);
        
        if (!depth_2_lmost_.count(depth)) {
            depth_2_lmost_[depth] = idx;
        } else {
            max_width_ = max(max_width_, idx - depth_2_lmost_[depth] + 1);
        }
        
        dfs(node->right, depth + 1, idx * 2 + 1);
    }
};
