#!/usr/bin/python3

'''
159. Find Minimum in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

Example
Given [4, 5, 6, 7, 0, 1, 2] return 0


Author: Yuan Li
Date: 5/20/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param nums: a rotated sorted array
    @return: the minimum number in the array
    """
    def findMin(self, nums):
        # write your code here
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = int((start + end) / 2)
            if nums[mid] <= nums[-1]:
                end = mid
            else:
                start = mid
                
        if nums[start] <= nums[-1]:
            return nums[start]
        return nums[end]
        