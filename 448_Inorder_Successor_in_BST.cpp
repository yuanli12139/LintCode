/*
448. Inorder Successor in BST
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

Example
Given tree = [2,1] and node = 1:

  2
 /
1
return node 2.

Given tree = [2,1,3] and node = 2:

  2
 / \
1   3
return node 3.

Challenge
O(h), where h is the height of the BST.

Notice
It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)


Author: Yuan Li
Date: 10/31/2018 
Difficulty: Medium
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        if (root == nullptr || p == nullptr) {
            return nullptr;
        }
        
        // go right
        if (p->val >= root->val) {
            return inorderSuccessor(root->right, p);
        }
        
        // go left
        TreeNode* left_res = inorderSuccessor(root->left, p);
        if (left_res) {
            return left_res;
        }
        return root;
    }
};

