#!/usr/bin/python3

'''
373. Partition Array by Odd and Even
Partition an integers array into odd number first and even number second.

Example
Given [1, 2, 3, 4], return [1, 3, 2, 4]

Challenge
Do it in-place.


Author: Yuan Li
Date: 6/17/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param: nums: an array of integers
    @return: nothing
    """
    def partitionArray(self, nums):
        # write your code here
        if nums == None or len(nums) <= 1:
            return
            
        left, right = 0, len(nums) - 1
        while left <= right:
            while left <= right and nums[left] % 2:
                left += 1
                
            while left <= right and ~nums[right] % 2:
                right -= 1
                
            if left <= right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        