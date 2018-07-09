#!/usr/bin/python3

'''
596. Minimum Subtree
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.

Example
Given a binary tree:

     1
   /   \
 -5     2
 / \   /  \
0   2 -4  -5 

return the node 1.


Author: Yuan Li
Date: 7/7/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param s: a string
    @return: return List[str]
    """
    def findRepeatedDnaSequences(self, s):
        # write your code here
        res = []
        hashTable = {}
        for i in range(len(s) - 9):
            sub = s[i:i+10]

            if sub in hashTable:
                hashTable[sub] += 1
                
            else:
                hashTable[sub] = 1
                
        for k in hashTable:
            if hashTable[k] > 1:
                res.append(k)
                
        return res
        