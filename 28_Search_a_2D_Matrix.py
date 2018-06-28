#!/usr/bin/python3

'''
28. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example
Consider the following matrix:

[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.

Challenge
O(log(n) + log(m)) time


Author: Yuan Li
Date: 6/27/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param matrix: matrix, a list of lists of integers
    @param target: An integer
    @return: a boolean, indicate whether matrix contains target
    """
    def searchMatrix(self, matrix, target):
        # write your code here
        if matrix == None or len(matrix) == 0:
            return False
            
        if matrix[0] == None or len(matrix[0]) == 0:
            return False
            
        n_row, n_col = len(matrix), len(matrix[0])
        start, end = 0, n_row * n_col - 1
        
        while start + 1 < end:
            mid = (start + end) // 2
            row, col = mid // n_col, mid % n_col
            
            if matrix[row][col] == target:
                return True
                
            if matrix[row][col] < target:
                start = mid
                
            else:
                end = mid
                
        if matrix[start//n_col][start%n_col] == target or \
        matrix[end//n_col][end%n_col] == target:
            return True
            
        return False
        