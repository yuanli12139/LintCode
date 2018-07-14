#!/usr/bin/python3

'''
901. Closest Binary Search Tree Value II
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

Example
Given root = {1}, target = 0.000000, k = 1, return [1].

Challenge
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?


Author: Yuan Li
Date: 7/13/2018 
Difficulty: Hard
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
    @param k: the given k
    @return: k values in the BST that are closest to the target
    """
    def closestKValues(self, root, target, k):
        # write your code here
        res = []
        if k == 0:
            return res
        
        # find lower & upper bound
        lowerStack = []
        
        # pretend inserting target
        while root:
            lowerStack.append(root)
            if target <= root.val:
                root = root.left
            else:
                root = root.right
                
        upperStack = lowerStack.copy()
        
        if target <= lowerStack[-1].val:
            self.moveLower(lowerStack)
        else:
            self.moveUpper(upperStack)
            
        # found lower & upper bound, now search kth closest
        for i in range(k):
            if not upperStack or \
            (lowerStack and \
            target - lowerStack[-1].val <= upperStack[-1].val - target):
                res.append(lowerStack[-1].val)
                self.moveLower(lowerStack)
            else:
                res.append(upperStack[-1].val)
                self.moveUpper(upperStack)
                
        return res
        
    def moveLower(self, stack):
        node = stack[-1]
        
        # left child exists, look for right most of the left child
        if node.left:
            node = node.left
            while node:
                stack.append(node)
                node = node.right
        
        # left child doesn't exist, look for first right turn
        else:
            stack.pop()
            while stack and stack[-1].left == node:
                node = stack.pop()
                
    def moveUpper(self, stack):
        node = stack[-1]
        
        # right child exists, look for left most of the right child
        if node.right:
            node = node.right
            while node:
                stack.append(node)
                node = node.left
                    
        # right child doesn't exist, look for first left turn
        else:
            stack.pop()
            while stack and stack[-1].right == node:
                node = stack.pop()
            