#!/usr/bin/python3

'''
428. Pow(x, n)
Implement pow(x, n).

Example
Pow(2.1, 3) = 9.261
Pow(0, 1) = 0
Pow(1, 0) = 1

Challenge
O(logn) time


Author: Yuan Li
Date: 5/20/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param: x: the base number
    @param: n: the power number
    @return: the result
    """
    def myPow(self, x, n):
        # write your code here
        if n < 0:
            x = 1 / x
            n = -n
            
        ans = 1
        tmp = x
        while n != 0:
            if n % 2 == 1:
                ans *= tmp
            tmp *= tmp
            n = int(n / 2)
                
        return ans
           