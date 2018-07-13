#!/usr/bin/python3

'''
67. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
 
return [1,3,2].

Challenge
Can you do it without recursion?


Author: Yuan Li
Date: 7/10/2018 
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
    @return: Inorder in ArrayList which contains node values.
    """
    def inorderTraversal(self, root):
        # write your code here
        res = []
        stack = []
        
        # find the left most node
        while root:
            stack.append(root)
            root = root.left
            
        while stack:
            node = stack[-1]
            res.append(node.val)
            
            # has right child, go to left most of the right child
            if node.right:
                node = node.right
                while node:
                    stack.append(node)
                    node = node.left
        
            else:
                node = stack.pop()
                
                # first left turn from parent
                while stack and node == stack[-1].right:
                    node = stack.pop()
                    
        return res
                