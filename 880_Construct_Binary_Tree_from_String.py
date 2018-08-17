#!/usr/bin/python3

'''
880. Construct Binary Tree from String
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example
Given s = "4(2(3)(1))(6(5))", return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   

Notice
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".


Author: Yuan Li
Date: 8/16/2018 
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
    @param s: a string
    @return: a root of this tree
    """
    def str2tree(self, s):
        # write your code here
        if s == None or s == '':
            return None
         
        n = ''
        while s and s[0] != '(':
            n += s[0]
            s = s[1:]
    
        node = TreeNode(int(n))

        ls, rs = self.separate(s)
        node.left = self.str2tree(ls)
        node.right = self.str2tree(rs)
        
        return node
        
    def separate(self, s):
        left, right = '', s 
        deg = 0

        while right:
            deg += {'(': 1, ')': -1}.get(right[0], 0)
            
            left += right[0]
            right = right[1:]
            
            if deg == 0:
                break

        return left[1:-1], right[1:-1]
