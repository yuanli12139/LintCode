#!/usr/bin/python3

'''
390. Find Peak Element II
There is an integer matrix which has the following features:

The numbers in adjacent positions are different.
The matrix has n rows and m columns.
For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].
We define a position P is a peek if:

A[j][i] > A[j+1][i] && A[j][i] > A[j-1][i] && A[j][i] > A[j][i+1] && A[j][i] > A[j][i-1]
Find a peak element in this matrix. Return the index of the peak.

Example
Given a matrix:

[
  [1 ,2 ,3 ,6 ,5],
  [16,41,23,22,6],
  [15,17,24,21,7],
  [14,18,19,20,10],
  [13,14,11,10,9]
]
return index of 41 (which is [1,1]) or index of 24 (which is [2,2])

Challenge
Solve it in O(n+m) time.

If you come up with an algorithm that you thought it is O(n log m) or O(m log n), can you prove it is actually O(n+m) or propose a similar but O(n+m) algorithm?

Notice
The matrix may contains multiple peeks, find any of them.


Author: Yuan Li
Date: 11/24/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param: A: An integer matrix
    @return: The index of the peak
    """
    def findPeakII(self, A):
        # write your code here
        if not A or not A[0]:
            return None
            
        return self.helper(A, 0, len(A) - 1, 0, len(A[0]) - 1)
        
    def helper(self, A, top, bottom, left, right):
        # when only a 2x2 submatrix is left
        if top + 1 >= bottom and left + 1 >= right:
            for r in range(top, bottom + 1):
                for c in range(left, right + 1):
                    if self.isPeak(A, r, c):
                        return [r, c]
            return [-1, -1]
        
        # binary search rows    
        if bottom - top > right - left:
            row = (top + bottom) // 2
            col = self.getRowPeak(A, row, left, right)
            
            if self.isPeak(A, row, col):
                return [row, col]
                
            if A[row-1][col] > A[row][col]:
                return self.helper(A, top, row, left, right) # go up
            return self.helper(A, row, bottom, left, right) # go down
            
        # binary search cols
        col = (left + right) // 2
        row = self.getColPeak(A, col, top, bottom)
        
        if A[row][col-1] > A[row][col]: 
            return self.helper(A, top, bottom, left, col) # go left
        return self.helper(A, top, bottom, col, right) # go right
    
    def isPeak(self, matrix, row, col):
        return matrix[row][col] == max(
            matrix[row][col], 
            matrix[row-1][col],
            matrix[row+1][col],
            matrix[row][col-1],
            matrix[row][col+1])
            
    def getRowPeak(self, matrix, row, left, right):
        peak_val = -sys.maxsize
        peak_col = 0
        for c in range(left, right + 1):
            if matrix[row][c] > peak_val:
                peak_val = matrix[row][c]
                peak_col = c
        return peak_col
                
    def getColPeak(self, matrix, col, top, bottom):
        peak_val = -sys.maxsize
        peak_row = 0
        for r in range(top, bottom + 1):
            if matrix[r][col] > peak_val:
                peak_val = matrix[r][col]
                peak_row = r
        return peak_row

