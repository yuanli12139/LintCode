/*
86. Binary Search Tree Iterator

Design an iterator over a binary search tree with the following rules:

Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.

Example
For the following binary search tree, in-order traversal by using iterator is [1, 6, 10, 11, 12]

   10
 /    \
1      11
 \       \
  6       12
  
Challenge
Extra memory usage O(h), h is the height of the tree.

Super Star: Extra memory usage O(1)


Author: Yuan Li
Date: 3/4/2019 
Difficulty: Hard
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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */

class BSTIterator {
  public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        while (root) {
            stk_.push(root);
            root = root->left;
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return !stk_.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode *next_node = stk_.top();
        TreeNode *node = next_node;
        
        // right child exsits, find the leftmost child of the right child
        if (node->right) {
            node = node->right;
            while (node) {
                stk_.push(node);
                node = node->left;
            }
        }
        
        // no right child, find the first left turn from parent
        else {
            stk_.pop();
            while (!stk_.empty() && stk_.top()->left != node) {
                node = stk_.top();
                stk_.pop();
            }
        }
        
        return next_node;
    }
    
  private:
    stack<TreeNode*> stk_;
};

