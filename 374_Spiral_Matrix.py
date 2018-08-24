#!/usr/bin/python3

'''
374. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].


Author: Yuan Li
Date: 8/23/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param matrix: a matrix of m x n elements
    @return: an integer list
    """
    def spiralOrder(self, matrix):
        # write your code here
        res = []
        if not matrix or not matrix[0]:
            return res
        
        n, m = len(matrix), len(matrix[0])
        top, bottom, left, right = 0, n - 1, 0, m - 1
        direct = 0
        
        while top <= bottom and left <= right:
            # go right
            if direct == 0:
                for c in range(left, right+1):
                    res.append(matrix[top][c])
                top += 1
                
            # go down
            if direct == 1:
                for r in range(top, bottom+1):
                    res.append(matrix[r][right])
                right -= 1
            
            # go left
            if direct == 2:
                for c in range(right, left-1, -1):
                    res.append(matrix[bottom][c])
                bottom -= 1
                
            # go up
            if direct == 3:
                for r in range(bottom, top-1, -1):
                    res.append(matrix[r][left])
                left += 1
                
            direct = (direct + 1) % 4
                
        return res
