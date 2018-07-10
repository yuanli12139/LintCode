#!/usr/bin/python3

'''
578. Lowest Common Ancestor III
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Node A or node B may not exist in tree.

Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6

LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7


Author: Yuan Li
Date: 7/9/2018 
Difficulty: Medium
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""

class Solution:
    """
    @param: root: The root of the binary tree.
    @param: A: A TreeNode
    @param: B: A TreeNode
    @return: Return the LCA of the two nodes.
    """
    def lowestCommonAncestor3(self, root, A, B):
        # write your code here
        A_exist, B_exist, lca = self.helper(root, A, B)
        
        if A_exist and B_exist:
            return lca
        return None
        
    def helper(self, node, A, B):
        if node == None:
            return False, False, None
            
        left_A_exist, left_B_exist, left = self.helper(node.left, A, B)
        right_A_exist, right_B_exist, right = self.helper(node.right, A, B)
        
        A_exist = left_A_exist or right_A_exist or node == A
        B_exist = left_B_exist or right_B_exist or node == B
        
        if node == A or node == B:
            return A_exist, B_exist, node
        
        if left and right:
            return A_exist, B_exist, node
            
        if left:
            return A_exist, B_exist, left
            
        if right:
            return A_exist, B_exist, right
            
        return A_exist, B_exist, None
        