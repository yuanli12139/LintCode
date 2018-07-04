#!/usr/bin/python3

'''
95. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
A single node tree is a BST

Example
An example:

  2
 / \
1   4
   / \
  3   5

The above binary tree is serialized as {2,1,4,#,#,3,5} (in level order).


Author: Yuan Li
Date: 7/3/2018 
Difficulty: Medium
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

# in-order traversal
class Solution:
    """
    @param root: The root of binary tree.
    @return: True if the binary tree is BST, or false
    """
    def isValidBST(self, root):
        # write your code here
        self.last_node = None
        self.is_valid = True
        
        self.inOrderTraverse(root)
        
        return self.is_valid
        
    def inOrderTraverse(self, node):
        if node == None:
            return
            
        self.inOrderTraverse(node.left)
        
        if self.last_node and self.last_node.val >= node.val:
            self.is_valid = False
            return
        
        self.last_node = node
        
        self.inOrderTraverse(node.right)
        

# divide and conquer
class Solution:
    """
    @param root: The root of binary tree.
    @return: True if the binary tree is BST, or false
    """
    def isValidBST(self, root):
        # write your code here
        isBST, _, _ = self.divideConquer(root)
        
        return isBST
        
    def divideConquer(self, node):
        if node == None:
            return True, None, None
            
        left_isBST, left_minNode, left_maxNode = self.divideConquer(node.left)
        right_isBST, right_minNode, right_maxNode = self.divideConquer(node.right)
        
        if not left_isBST or not right_isBST:
            return False, None, None
            
        if left_maxNode and left_maxNode.val >= node.val:
            return False, None, None
            
        if right_minNode and right_minNode.val <= node.val:
            return False, None, None
    
        # is a BST
        minNode = left_minNode if left_minNode else node
        maxNode = right_maxNode if right_maxNode else node
        
        return True, minNode, maxNode
        