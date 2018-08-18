#!/usr/bin/python3

'''
1347. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Notice
Your solution should be in logarithmic time complexity.

Reference
https://blog.csdn.net/qq_34861102/article/details/80820501


Author: Yuan Li
Date: 8/16/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param n: a integer
    @return: return a integer
    """
    def trailingZeroes(self, n):
        # write your code here
        if n < 5:
            return 0
            
        return self.trailingZeroes(n // 5) + n // 5 
