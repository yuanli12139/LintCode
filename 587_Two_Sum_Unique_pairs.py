#!/usr/bin/python3

'''
587. Two Sum - Unique pairs
Given an array of integers, find how many unique pairs in the array such that their sum is equal to a specific target number. Please return the number of pairs.

Example
Given nums = [1,1,2,45,46,46], target = 47
return 2

1 + 46 = 47
2 + 45 = 47


Author: Yuan Li
Date: 6/13/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param nums: an array of integer
    @param target: An integer
    @return: An integer
    """
    def twoSum6(self, nums, target):
        # write your code here
        nums.sort()
        
        left, right = 0, len(nums) - 1
        count = 0
        while left < right:
            if nums[left] + nums[right] == target:
                count += 1
                left += 1
                right -= 1
            
                while left < right and nums[left] == nums[left-1]:
                    left += 1
                while left < right and nums[right] == nums[right+1]:
                    right -= 1
                
            elif nums[left] + nums[right] > target:
                right -= 1
            else:
                left += 1
                
        return count
        