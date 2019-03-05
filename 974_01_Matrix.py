#!/usr/bin/python3

'''
974. 01 Matrix

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example
Example 1:

Input:
[[0,0,0],
 [0,0,0],
 [0,0,0],
 [0,0,0],
 [0,0,0]]
Output:
[[0,0,0],
 [0,0,0],
 [0,0,0],
 [0,0,0],
 [0,0,0]]

Example 2:

Input:
[[0,1,0,1,1],
 [1,1,0,0,1],
 [0,0,0,1,0],
 [1,0,1,1,1],
 [1,0,0,0,1]]
Output:
[[0,1,0,1,2],
 [1,1,0,0,1],
 [0,0,0,1,0],
 [1,0,1,1,1],
 [1,0,0,0,1]]

Notice
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.


Author: Yuan Li
Date: 3/3/2019 
Difficulty: Medium
'''

class Solution:
    """
    @param matrix: a 0-1 matrix
    @return: return a matrix
    """
    def updateMatrix(self, matrix):
        # write your code here  
        n, m = len(matrix), len(matrix[0])                     
        dp = [[99 for _ in range(m + 2)] for _ in range(n + 2)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if matrix[i-1][j-1] == 0:
                    dp[i][j] = 0
                    continue
                             
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1
    
        for i in range(n, 0, -1):
            for j in range(m, 0, -1):
                dp[i][j] = min(dp[i][j], dp[i+1][j] + 1, dp[i][j+1] + 1)
                             
        return [dp[i][1:-1] for i in range(1, n + 1)]
