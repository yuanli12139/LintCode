#!/usr/bin/python3

'''
168. Burst Balloons
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example
Given [4, 1, 5, 10]
Return 270

nums = [4, 1, 5, 10] burst 1, get coins 4 * 1 * 5 = 20
nums = [4, 5, 10]    burst 5, get coins 4 * 5 * 10 = 200 
nums = [4, 10]       burst 4, get coins 1 * 4 * 10 = 40
nums = [10]          burst 10, get coins 1 * 10 * 1 = 10

Total coins 20 + 200 + 40 + 10 = 270


Author: Yuan Li
Date: 1/27/2019 
Difficulty: Hard
'''

class Solution:
    """
    @param nums: A list of integer
    @return: An integer, maximum coins
    """
    def maxCoins(self, nums):
        # write your code here
        if not nums:
            return 0
            
        nums = [1, *nums, 1]
        n = len(nums)
        
        # maximum coins collected from bursting all balloons within (i, j)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(i + 2, n):
                # k is the last ballon bursted between i, j
                for k in range(i + 1, j):
                    coins = nums[i] * nums[k] * nums[j]
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + coins)
                    
        return dp[0][n-1]

