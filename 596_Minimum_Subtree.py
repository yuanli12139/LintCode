#!/usr/bin/python3

'''
596. Minimum Subtree
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.

Example
Given a binary tree:

     1
   /   \
 -5     2
 / \   /  \
0   2 -4  -5 

return the node 1.


Author: Yuan Li
Date: 7/7/2018 
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
    @param root: the root of binary tree
    @return: the root of the minimum subtree
    """
    def __init__(self):
        self.minSubTree = None
        self.minSum = float("inf")
    
    def findSubtree(self, root):
        # write your code here
        self.helper(root)
        return self.minSubTree
        
    def helper(self, node):
        if node == None:
            return 0
            
        s = node.val + self.helper(node.left) + self.helper(node.right)
        
        if s < self.minSum:
            self.minSum = s
            self.minSubTree = node
            
        return s
        