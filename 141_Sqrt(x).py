#!/usr/bin/python3

'''
141. Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x.

Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3

Challenge
O(log(x))


Author: Yuan Li
Date: 11/24/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
        start, end = 0, x
        while start + 1 < end:
            mid = (start + end) // 2
            if mid * mid <= x:
                start = mid
            else:
                end = mid
                
        if end * end <= x:
            return end
        return start

