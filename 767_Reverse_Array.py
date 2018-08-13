#!/usr/bin/python3

'''
767. Reverse Array
Reverse the given array nums inplace.

Example
Given nums = [1,2,5]
return [5,2,1]

Notice
Inplace means you can't use extra space.


Author: Yuan Li
Date: 8/13/2018 
Difficulty: Easy
'''

"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param nums: a integer array
    @return: nothing
    """
    def reverseArray(self, nums):
        # write your code here
        i, j = 0, len(nums) - 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
            
        return nums
