#!/usr/bin/python3

'''
453. Flatten Binary Tree to Linked List
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.

Example
              1
               \
     1          2
    / \          \
   2   5    =>    3
  / \   \          \
 3   4   6          4
                     \
                      5
                       \
                        6

Challenge
Do it in-place without any extra memory.


Author: Yuan Li
Date: 7/9/2018 
Difficulty: Easy
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

# divide and conquer
class Solution:
    """
    @param root: a TreeNode, the root of the binary tree
    @return: nothing
    """
    def flatten(self, root):
        # write your code here
        if root == None:
            return None
            
        leftLast = self.flatten(root.left)
        rightLast = self.flatten(root.right)
            
        if leftLast:
            leftLast.right = root.right
            root.right = root.left
            root.left = None
            
        if rightLast:
            return rightLast
            
        if leftLast:
            return leftLast
            
        return root
        

# traversal
class Solution:
#     """
#     @param root: a TreeNode, the root of the binary tree
#     @return: nothing
#     """
    def __init__(self):
        self.lastNode = None
    
    def flatten(self, root):
        # write your code here
        if root == None:
            return None
            
        if self.lastNode:
            self.lastNode.left = None
            self.lastNode.right = root
            
        self.lastNode = root
        right = root.right
        self.flatten(root.left) # root.right is changed in this call
        self.flatten(right)
        