#!/usr/bin/python3

'''
69. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Challenge
Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use DFS algorithm to do it.


Author: Yuan Li
Date: 6/19/2018 
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
    @param root: A Tree
    @return: Level order a list of lists of integer
    """
    def levelOrder(self, root):
        # write your code here
        res = []
        
        if root == None:
            return res
            
        queue = [root]
        while queue:
            level = []
            for i in range(len(queue)):
                head = queue.pop(0)
                level.append(head.val)
                
                if head.left:
                    queue.append(head.left)
                    
                if head.right:
                    queue.append(head.right)
                    
            res.append(level)
            
        return res
                