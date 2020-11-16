#!/usr/bin/python3

'''
617. Maximum Average Subarray II
Given an array with positive and negative numbers, find the maximum average subarray which length should be greater or equal to given length k.

Example
Given nums = [1, 12, -5, -6, 50, 3], k = 3

Return 15.667 // (-6 + 50 + 3) / 3 = 15.667

Notice
It's guaranteed that the size of the array is greater or equal to k.


Author: Yuan Li
Date: 11/25/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param nums: an array with positive and negative numbers
    @param k: an integer
    @return: the maximum average
    """
    def maxAverage(self, nums, k):
        # write your code here
        if not nums:
            return 0
            
        start, end = min(nums), max(nums)
        while start + 1e-5 < end:
            mid = (start + end) / 2
            if self.isValid(nums, k, mid): # find answer, adjust up
                start = mid
            else:
                end = mid
                
        return start
        
    def isValid(self, nums, k, average):
        prefix_sum = [0]
        for num in nums:
            prefix_sum.append(prefix_sum[-1] + num - average)
            
        min_sum = 0
        for i in range(k, len(prefix_sum)):
            if prefix_sum[i] - min_sum >= 0:
                return True
            min_sum = min(min_sum, prefix_sum[i-k+1])
        
        return False

