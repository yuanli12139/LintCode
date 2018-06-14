#!/usr/bin/python3

'''
608. Two Sum II - Input array is sorted
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

Example
Given nums = [2, 7, 11, 15], target = 9
return [1, 2]


Author: Yuan Li
Date: 6/13/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param nums: an array of Integer
    @param target: target = nums[index1] + nums[index2]
    @return: [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, nums, target):
        # write your code here
        index1, index2 = 0, len(nums) - 1
        while index1 < index2:
            if nums[index1] + nums[index2] == target:
                return [index1 + 1, index2 + 1]
            if nums[index1] + nums[index2] > target:
                index2 -= 1
            else:
                index1 += 1
        