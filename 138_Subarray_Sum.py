#!/usr/bin/python3

'''
138. Subarray Sum
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

Example
Example 1:
	Input:  [-3, 1, 2, -3, 4]
	Output: [0, 2] or [1, 3].
	
	Explanation:
	return anyone that the sum is 0.

Example 2:
	Input:  [-3, 1, -4, 2, -3, 4]
	Output: [1,5]
	

Notice
There is at least one subarray that it's sum equals to zero.


Author: Yuan Li
Date: 2/1/2019 
Difficulty: Easy
'''

class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def subarraySum(self, nums):
        # write your code here
        pre_sum = 0
        sum_idx = {0: -1}
        
        for i, num in enumerate(nums):
            pre_sum += num
            if pre_sum in sum_idx:
                return sum_idx[pre_sum] + 1, i
            
            sum_idx[pre_sum] = i
                
        return -1, -1

