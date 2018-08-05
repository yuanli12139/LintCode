#!/usr/bin/python3

'''
900. Closest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

Example
Given root = {1}, target = 4.428571, return 1.


Author: Yuan Li
Date: 7/13/2018 
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
    @param root: the given BST
    @param target: the given target
    @return: the value in the BST that is closest to the target
    """
    def closestValue(self, root, target):
        # write your code here
        if root == None:
            return None
        
        lower = self.lowerClosest(root, target)
        upper = self.upperClosest(root, target)
        
        if lower == None:
            return upper.val
            
        if upper == None:
            return lower.val
            
        if target - lower.val <= upper.val - target:
            return lower.val
            
        return upper.val
        
    def lowerClosest(self, node, target):
        if node == None:
            return None
            
        if target <= node.val:
            return self.lowerClosest(node.left, target)
            
        # look for a node with val that is between target and node->val
        lower = self.lowerClosest(node.right, target)
        if lower:
            return lower
            
        return node

    def upperClosest(self, node, target):
        if node == None:
            return None
        
        if target > node.val:
            return self.upperClosest(node.right, target)
        
        # look for a node with val that is between target and node->val    
        upper = self.upperClosest(node.left, target)
        if upper:
            return upper
            
        return node
            