#!/usr/bin/python3

'''
126. Max Tree
Given an integer array with no duplicates. A max tree building on this array is defined as follow:

The root is the maximum number in the array
The left subtree and right subtree are the max trees of the subarray divided by the root number.
Construct the max tree by the given array.

Example
Given [2, 5, 6, 0, 3, 1], the max tree constructed by this array is:

    6
   / \
  5   3
 /   / \
2   0   1

Challenge
O(n) time and memory.


Author: Yuan Li
Date: 11/14/2018 
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
    @param A: Given an integer array with no duplicates.
    @return: The root of max tree.
    """
    def maxTree(self, A):
        # write your code here
        if not A:
            return None
            
        nodes = [TreeNode(num) for num in A + [sys.maxsize]]
        
        idx_stk = []
        for i, num in enumerate(A + [sys.maxsize]):
            while idx_stk and A[idx_stk[-1]] <= num: 
                i_pop = idx_stk.pop()
                
                i_left = idx_stk[-1] if idx_stk else -1
                left = A[idx_stk[-1]] if i_left >= 0 else sys.maxsize

                if left < num:
                    nodes[i_left].right = nodes[i_pop]
                else:
                    nodes[i].left = nodes[i_pop]
                    
            idx_stk.append(i)
            
        # sys.maxsize 's left child is the maximum number
        return nodes[-1].left

