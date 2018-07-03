#!/usr/bin/python3

'''
97. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example
Given a binary tree as follow:

  1
 / \ 
2   3
   / \
  4   5  
The maximum depth is 3.


Author: Yuan Li
Date: 7/2/2018 
Difficulty: Easy
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

# traversal
class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def __init__(self):
        self.depth = 0
    
    def maxDepth(self, root):
        # write your code here
        self.traverse(root, 1)
        return self.depth
        
    def traverse(self, node, currDepth):
        if node == None:
            return
        
        self.depth = max(self.depth, currDepth)
        
        self.traverse(node.left, currDepth+1)
        self.traverse(node.right, currDepth+1)
        

# divide and conquer
class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def maxDepth(self, root):
        # write your code here
        if root == None:
            return 0
        
        leftDepth = self.maxDepth(root.left)
        rightDepth = self.maxDepth(root.right)
        
        return max(leftDepth, rightDepth) + 1
