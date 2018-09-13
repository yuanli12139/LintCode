#!/usr/bin/python3

'''
427. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example
Given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"


Author: Yuan Li
Date: 6/16/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param n: n pairs
    @return: All combinations of well-formed parentheses
    """
    def generateParenthesis(self, n):
        # write your code here
        res = []
        self.helper(n, n, "", res)
        return res

    def helper(self, l, r, item, res):
        if r < l:
            return
        
        if l == 0 and r == 0:
            res.append(item)
            return
            
        if l > 0:
            self.helper(l - 1, r, item + '(', res)
            
        if r > 0:
            self.helper(l, r - 1, item + ')', res)
    
        
