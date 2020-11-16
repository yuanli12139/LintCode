#!/usr/bin/python3

'''
586. Sqrt(x) II
Implement double sqrt(double x) and x >= 0.

Compute and return the square root of x.

Example
Given n = 2 return 1.41421356

Notice
You do not care about the accuracy of the result, we will help you to output results.


Author: Yuan Li
Date: 11/24/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param x: a double
    @return: the square root of x
    """
    def sqrt(self, x):
        # write your code here
        start, end = 0, max(x, 1)
        while start + 1e-12 < end:
            mid = (start + end) / 2
            if mid * mid <= x:
                start = mid
            else:
                end = mid

        # no need to check start or end, both are accurate enough                
        return start

