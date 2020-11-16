#!/usr/bin/python3

'''
139. Subarray Sum Closest
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Example
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].

Challenge
O(nlogn) time

Author: Yuan Li
Date: 2/6/2019 
Difficulty: Medium
'''

class Solution:
    """
    @param: nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def subarraySumClosest(self, nums):
        # write your code here
        pre_sum = [(0, -1)]
        for i, num in enumerate(nums):
            pre_sum.append((pre_sum[-1][0] + num, i))
            
        pre_sum.sort()    
            
        min_sum = sys.maxsize    
        res = []
        
        for i in range(1, len(pre_sum)):
            if pre_sum[i][0] - pre_sum[i-1][0] < min_sum:
                left_id = min(pre_sum[i-1][1], pre_sum[i][1]) + 1
                right_id = max(pre_sum[i-1][1], pre_sum[i][1])
                
                res = [left_id, right_id]
                
                min_sum = pre_sum[i][0] - pre_sum[i-1][0]
            
        return res

