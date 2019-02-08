#!/usr/bin/python3

'''
405. Submatrix Sum

Given an integer matrix, find a submatrix where the sum of numbers is zero. Your code should return the coordinate of the left-up and right-down number.

If there are multiple answers, you can return any of them.

Example
Example 1:

Input:
[
  [1, 5, 7],
  [3, 7, -8],
  [4, -8 ,9]
]
Output: [[1, 1], [2, 2]]

Example 2:

Input:
[
  [0, 1],
  [1, 0]
]
Output: [[0, 0], [0, 0]]

Challenge
O(n3) time.

Author: Yuan Li
Date: 2/7/2019 
Difficulty: Medium
'''

class Solution:
    """
    @param: matrix: an integer matrix
    @return: the coordinate of the left-up and right-down number
    """
    def submatrixSum(self, matrix):
        # write your code here
        if not matrix or not matrix[0]:
            return None
            
        n, m = len(matrix), len(matrix[0])
        for t in range(n):
            pre_sum_row = [0] * m
            
            for b in range(t, n):
                pre_sum_col = 0
                sum_col = {0: -1}
                
                # subarray sum problem
                for c in range(m):
                    pre_sum_row[c] += matrix[b][c]
                    pre_sum_col += pre_sum_row[c]
                    
                    if pre_sum_col in sum_col:
                        return [[t, sum_col[pre_sum_col] + 1], [b, c]]
                    
                    sum_col[pre_sum_col] = c
                        
        return None

