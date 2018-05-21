#!/usr/bin/python3

'''
140. Fast Power
Calculate the a^n % b where a, b and n are all 32bit integers.

Example
For 231 % 3 = 2

For 1001000 % 1000 = 0

Challenge
O(logn)


Author: Yuan Li
Date: 5/20/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param a: A 32bit integer
    @param b: A 32bit integer
    @param n: A 32bit integer
    @return: An integer
    """
    def fastPower(self, a, b, n):
        # write your code here
        if n == 0:
            return 1 % b
        if n == 1:
            return a % b
            
        result = self.fastPower(a, b, int(n/2))
        result = result**2 % b
        if n % 2 == 1:
            result = result * a % b
            
        return result
      