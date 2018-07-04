#!/usr/bin/python3

'''
93. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example
Given binary tree A = {3,9,20,#,#,15,7}, B = {3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.


Author: Yuan Li
Date: 7/3/2018
Difficulty: Easy
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
    @param root: The root of binary tree.
    @return: True if this Binary tree is Balanced, or false.
    """
    def isBalanced(self, root):
        # write your code here
        _, is_balanced = self.maxDepth(root)
        return is_balanced
        
    def maxDepth(self, node):
        if node == None:
            return 0, True
            
        left_depth, is_left_balanced = self.maxDepth(node.left)
        right_depth, is_right_balanced = self.maxDepth(node.right)
        
        if not is_left_balanced or not is_right_balanced:
            return -1, False

        if abs(left_depth - right_depth) > 1:
            return -1, False
        
        return max(left_depth, right_depth) + 1, True
