#!/usr/bin/python3

'''
392. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example
Given [3, 8, 4], return 8.

Challenge
O(n) time and O(1) memory.


Author: Yuan Li
Date: 11/28/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param A: An array of non-negative integers
    @return: The maximum amount of money you can rob tonight
    """
    def houseRobber(self, A):
        # write your code here
        if not A:
            return 0
        if len(A) <= 2:
            return max(A)
            
        dp = [0] * 3
        dp[0], dp[1] = A[0], max(A[0], A[1])
        
        for i in range(2, len(A)):
            dp[i%3] = max(A[i] + dp[(i-2)%3], dp[(i-1)%3])
            
        return dp[(len(A)-1)%3]

