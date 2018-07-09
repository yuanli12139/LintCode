#!/usr/bin/python3

'''
474. Lowest Common Ancestor II
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor (LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

The node has an extra attribute parent which point to the father of itself. The root's parent is null.

Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6

LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7


Author: Yuan Li
Date: 7/8/2018 
Difficulty: Easy
'''

"""
Definition of ParentTreeNode:
class ParentTreeNode:
    def __init__(self, val):
        self.val = val
        self.parent, self.left, self.right = None, None, None
"""

class Solution:
    """
    @param: root: The root of the tree
    @param: A: node in the tree
    @param: B: node in the tree
    @return: The lowest common ancestor of A and B
    """
    def lowestCommonAncestorII(self, root, A, B):
        # write your code here
        A_to_root = []
        while A is not None:
            A_to_root.append(A)
            A = A.parent
        
        B_to_root = []
        while B is not None:
            B_to_root.append(B)
            B = B.parent
   
        lca = root
        while A_to_root and B_to_root:
            if A_to_root[-1] == B_to_root[-1]:
                lca = A_to_root[-1]
                
            A_to_root.pop()
            B_to_root.pop()
            
        return lca
            