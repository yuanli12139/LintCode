/*
900. Closest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

Example
Given root = {1}, target = 4.428571, return 1.


Author: Yuan Li
Date: 8/4/2018 
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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        if (root == nullptr) {
            return 0;
        }
        
        TreeNode* lower = lowerClosest(root, target);
        TreeNode* upper = upperClosest(root, target);
        
        if (lower == nullptr) {
            return upper->val;
        }
        
        if (upper == nullptr) {
            return lower->val;
        }
        
        if (target - lower->val < upper->val - target) {
            return lower->val;
        }
        
        return upper->val;
    }
    
    TreeNode* lowerClosest(TreeNode* node, double target) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (target <= node->val) {
            return lowerClosest(node->left, target);
        }
        
        // look for a node with val that is between target and node->val
        TreeNode* rightLower = lowerClosest(node->right, target);
        if (rightLower) {
            return rightLower;
        }
        
        return node;
    }
    
    TreeNode* upperClosest(TreeNode* node, double target) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (target > node->val) {
            return upperClosest(node->right, target);
        }
        
        // look for a node with val that is between target and node->val
        TreeNode* leftUpper = upperClosest(node->left, target);
        if (leftUpper) {
            return leftUpper;
        }
        
        return node;
    }
};
