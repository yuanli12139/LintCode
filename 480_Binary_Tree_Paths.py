#!/usr/bin/python3

'''
480. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.

Example
Given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

[
  "1->2->5",
  "1->3"
]


Author: Yuan Li
Date: 7/8/2018 
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
    @param root: the root of the binary tree
    @return: all root-to-leaf paths
    """
    def binaryTreePaths(self, root):
        # write your code here
        res = []
        if root == None:
            return res
            
        self.helper(root, str(root.val), res)
        
        return res 
        
    def helper(self, node, path, res):
        if node == None:
            return
        
        if not node.left and not node.right:
            res.append(path)
            return
        
        if node.left:
            self.helper(node.left, path + "->" + str(node.left.val), res)
            
        if node.right:
            self.helper(node.right, path + "->" + str(node.right.val), res)
 
 
# divide and conquer
class Solution:
    """
    @param root: the root of the binary tree
    @return: all root-to-leaf paths
    """
    def binaryTreePaths(self, root):
        # write your code here
        paths = []
        
        if root == None:
            return paths
            
        leftPaths = self.binaryTreePaths(root.left)
        rightPaths = self.binaryTreePaths(root.right)
        
        if not leftPaths and not rightPaths:
            paths.append(str(root.val))
            return paths
        
        for p in leftPaths:
            paths.append(str(root.val) + "->" + p)
            
        for p in rightPaths:
            paths.append(str(root.val) + "->" + p)
            
        return paths
        