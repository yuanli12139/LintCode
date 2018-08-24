#!/usr/bin/python3

'''
488. Happy Number
Write an algorithm to determine if a number is happy.

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example
19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1


Author: Yuan Li
Date: 8/23/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param n: An integer
    @return: true if this is a happy number or false
    """
    def isHappy(self, n):
        # write your code here
        seen = set()
        
        # only 1 and 7 won't loop
        while n != 1 and n != 7: # or while n != 1:
            if n in seen:
                return False
                
            seen.add(n)
            n = self.nextSum(n)
        
        return True
            
    def nextSum(self, n):
        s = 0
        while n != 0:
            s += (n % 10)**2
            n //= 10
            
        return s
