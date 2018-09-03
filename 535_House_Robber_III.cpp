/*
535. House Robber III
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example
  3
 / \
2   3
 \   \ 
  3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

    3
   / \
  4   5
 / \   \ 
1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

Notice
这题是House Robber和House Robber II的扩展，只不过这次地形由直线和圈变成了二叉树


Author: Yuan Li
Date: 9/2/2018 
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
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        // write your code here
        Result res = visit(root);
        return max(res.rob, res.not_rob);
    }
    
  private:
    struct Result {
        Result() : rob(0), not_rob(0) {}
        
        int rob; 
        int not_rob;
    };
    
  private:
    Result visit(TreeNode* node) {
        Result res;
        if (node == nullptr) {
            return res;
        }
        
        Result left = visit(node->left);
        Result right = visit(node->right);
        
        res.rob = node->val + left.not_rob + right.not_rob;
        res.not_rob = max(left.rob, left.not_rob) + max(right.rob, right.not_rob);
        
        return res;
    }
};
