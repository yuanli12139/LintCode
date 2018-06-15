#!/usr/bin/python3

'''
533. Two Sum - Closest to target
Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

Return the difference between the sum of the two integers and the target.

Example
Given array nums = [-1, 2, 1, -4], and target = 4.

The minimum difference is 1. (4 - (2 + 1) = 1).

Challenge
Do it in O(nlogn) time complexity.


Author: Yuan Li
Date: 6/14/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param nums: an integer array
    @param target: An integer
    @return: the difference between the sum and the target
    """
    def twoSumClosest(self, nums, target):
        # write your code here
        if nums == None or len(nums) < 2:
            return
        
        nums.sort()
        
        diff = abs(target - (nums[0] + nums[1]))
        left, right = 0, len(nums) - 1
        while left < right:
            if nums[left] + nums[right] < target:
                diff = min(diff, target - nums[left] - nums[right])
                left += 1
                
            else:
                diff = min(diff, nums[left] + nums[right] - target)
                right -= 1
                
        return diff
        