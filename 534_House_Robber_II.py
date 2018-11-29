#!/usr/bin/python3

'''
534. House Robber II
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example
nums = [3,6,4], return 6

Notice
This is an extension of House Robber.


Author: Yuan Li
Date: 11/29/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param nums: An array of non-negative integers.
    @return: The maximum amount of money you can rob tonight
    """
    def houseRobber2(self, nums):
        # write your code here
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
            
        return max(self.helper(nums[:-1]), self.helper(nums[1:]))
        
    def helper(self, A):
        dp = [0] * len(A)
        
        dp[0], dp[1] = A[0], max(A[0], A[1])
        for i in range(2, len(A)):
            dp[i%3] = max(dp[(i-2)%3] + A[i], dp[(i-1)%3])
            
        return dp[(len(A)-1)%3]

