#!/usr/bin/python3

'''
944. Maximum Submatrix

Given an n x n matrix of positive and negative integers, find the submatrix with the largest possible sum.

Example
Given matrix = 
[
[1,3,-1],
[2,3,-2],
[-1,-2,-3]
]
return 9.

Explanation:
the submatrix with the largest possible sum is:
[
[1,3],
[2,3]
]

Author: Yuan Li
Date: 2/17/2019 
Difficulty: Medium
'''

class Solution:
    """
    @param matrix: the given matrix
    @return: the largest possible sum
    """
    def maxSubmatrix(self, matrix):
        # write your code here
        if not matrix or not matrix[0]:
            return 0
            
        pre_col_sum = self.getColPreSum(matrix)
        
        res = 0
        for up in range(len(matrix)):
            for down in range(up, len(matrix)):
                arr = self.getCompressedArr(pre_col_sum, up, down)
                res = max(res, self.getMaxSubArrSum(arr))
                
        return res
        
    def getColPreSum(self, matrix):
        n = len(matrix)
        pre_col_sum = [[0] * n for _ in range(n + 1)]
        
        for r in range(n):
            for c in range(n):
                pre_col_sum[r + 1][c] = pre_col_sum[r][c] + matrix[r][c]
                
        return pre_col_sum
                
    def getCompressedArr(self, pre_col_sum, up, down):
        m = len(pre_col_sum[0])
        arr = [0] * m
        
        for c in range(m):
            arr[c] = pre_col_sum[down+1][c] - pre_col_sum[up][c]
            
        return arr
        
    def getMaxSubArrSum(self, arr):
        pre_sum = 0
        min_sum = 0
        
        res = 0
        for n in arr:
            pre_sum += n
            res = max(res, pre_sum - min_sum)
            min_sum = min(min_sum, pre_sum)
            
        return res

