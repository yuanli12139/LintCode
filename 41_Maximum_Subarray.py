#!/usr/bin/python3

'''
41. Maximum Subarray
Given an array of integers, find a contiguous subarray which has the largest sum.

Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Challenge
Can you do it in time complexity O(n)?

Notice
The subarray should contain at least one number.


Author: Yuan Li
Date: 8/16/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param nums: A list of integers
    @return: A integer indicate the sum of max subarray
    """
    def maxSubArray(self, nums):
        # write your code here
        if not nums:
            return 0
        
        preSum = 0
        minPreSum = 0
        maxSum = nums[0]
        
        for num in nums:
            preSum += num
            maxSum = max(preSum - minPreSum, maxSum)
            minPreSum = min(preSum, minPreSum)
            
        return maxSum
