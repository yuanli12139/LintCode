#!/usr/bin/python3

'''
88. Lowest Common Ancestor of a Binary Tree
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor (LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

Assume two nodes are exist in tree.

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
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param: root: The root of the binary search tree.
    @param: A: A TreeNode in a Binary.
    @param: B: A TreeNode in a Binary.
    @return: Return the least common ancestor (LCA) of the two nodes.
    """
    def lowestCommonAncestor(self, root, A, B):
        # write your code here
        if root == None or root == A or root == B:
            return root
            
        # divide
        left = self.lowestCommonAncestor(root.left, A, B)
        right = self.lowestCommonAncestor(root.right, A, B)
        
        # conquer
        if left and right:
            return root
            
        if left:
            return left
            
        if right:
            return right
            
        return None
