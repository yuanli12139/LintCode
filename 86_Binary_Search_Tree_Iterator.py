#!/usr/bin/python3

'''
86. Binary Search Tree Iterator
Design an iterator over a binary search tree with the following rules:

Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.

Example
For the following binary search tree, in-order traversal by using iterator is [1, 6, 10, 11, 12]

   10
 /    \
1      11
 \       \
  6       12

Challenge
Extra memory usage O(h), h is the height of the tree.

Super Star: Extra memory usage O(1)


Author: Yuan Li
Date: 7/12/2018 
Difficulty: Hard
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

Example of iterate a tree:
iterator = BSTIterator(root)
while iterator.hasNext():
    node = iterator.next()
    do something for node 
"""

class BSTIterator:
    """
    @param: root: The root of binary tree.
    """
    def __init__(self, root):
        # do intialization if necessary
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    """
    @return: True if there has next node, or false
    """
    def hasNext(self, ):
        # write your code here
        return len(self.stack) > 0

    """
    @return: return next node
    """
    def next(self, ):
        # write your code here
        # fetch next node
        nextNode = self.stack[-1]
        node = nextNode
 
        # adjust stack
        # has right child, go to the left most of the right child
        if node.right:
            node = node.right
            while node:
                self.stack.append(node)
                node = node.left
                
        else:
            node = self.stack.pop() # pop currNode
            
            # find first left turn from parent
            while self.stack and self.stack[-1].right == node:
                node = self.stack.pop()
            
        return nextNode
