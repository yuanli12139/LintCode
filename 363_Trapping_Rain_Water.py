#!/usr/bin/python3

'''
363. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Picture
https://lintcode-media.s3.amazonaws.com/problem/rainwatertrap.png

Example
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Challenge
O(n) time and O(1) memory

O(n) time and O(n) memory is also acceptable.


Author: Yuan Li
Date: 11/4/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param heights: a list of integers
    @return: a integer
    """
    def trapRainWater(self, heights):
        # write your code here
        n = len(heights)
        
        left_max = []
        curr_max = -sys.maxsize
        for i in range(n):
            curr_max = max(curr_max, heights[i])
            left_max.append(curr_max)
            
        right_max = [0] * n
        curr_max = -sys.maxsize
        for j in range(n - 1, -1, -1):
            curr_max = max(curr_max, heights[j])
            right_max[j] = curr_max
    
        water = 0
        for i in range(n):
            water += min(left_max[i], right_max[i]) - heights[i]
            
        return water

