#!/usr/bin/python3

'''
38. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.

Example
Consider the following matrix:

[
  [1, 3, 5, 7],
  [2, 4, 7, 8],
  [3, 5, 9, 10]
]
Given target = 3, return 2.

Challenge
O(m+n) time and O(1) extra space


Author: Yuan Li
Date: 6/27/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param matrix: A list of lists of integers
    @param target: An integer you want to search in matrix
    @return: An integer indicate the total occurrence of target in the given matrix
    """
    def searchMatrix(self, matrix, target):
        # write your code here
        if matrix == None or len(matrix) == 0:
            return 0
            
        if matrix[0] == None or len(matrix[0]) == 0:
            return 0
            
        count = 0
        r, c = 0, len(matrix[0]) - 1
        while r < len(matrix) and c >= 0:
            if matrix[r][c] == target:
                count += 1
                r += 1
                c -= 1
                
            elif matrix[r][c] < target:
                r += 1
                
            else:
                c -= 1
                
        return count
            