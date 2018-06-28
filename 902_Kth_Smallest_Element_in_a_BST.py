#!/usr/bin/python3

'''
902. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example
Given root = {1,#,2}, k = 2, return 2.

Challenge
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


Author: Yuan Li
Date: 6/27/2018 
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
    @param root: the given BST
    @param k: the given k
    @return: the kth smallest element in BST
    """
    def __init__(self):
        self.count = 0
        self.res = None
    
    def kthSmallest(self, root, k):
        # write your code here
        self.inOrder(root, k)
        return self.res
        
    def inOrder(self, root, k):
        if root:
            self.inOrder(root.left, k)

            self.count += 1
            if self.count == k:
                self.res = root.val
                return
            
            self.inOrder(root.right, k)
        