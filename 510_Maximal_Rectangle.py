#!/usr/bin/python3

'''
510. Maximal Rectangle
Given a 2D boolean matrix filled with False and True, find the largest rectangle containing all True and return its area.

Example
Given a matrix:

[
  [1, 1, 0, 0, 1],
  [0, 1, 0, 0, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 0, 0, 1]
]
return 6.


Author: Yuan Li
Date: 11/14/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param matrix: a boolean 2D matrix
    @return: an integer
    """
    def maximalRectangle(self, matrix):
        # write your code here
        max_rect = 0
        
        if not matrix:
            return max_rect
        
        curr_heights = [0] * len(matrix[0])
        for row in matrix:
            curr_heights = [sum(x) * x[1] for x in zip(curr_heights, row)]
            max_rect = max(max_rect, self.getMaxArea(curr_heights))
            
        return max_rect    
        
    def getMaxArea(self, heights):
        max_area = 0
        
        idx_stack = []
        for i, h in enumerate(heights + [0]):
            while idx_stack and heights[idx_stack[-1]] >= h:
                i_pop = idx_stack.pop()
                i_left = idx_stack[-1] if idx_stack else -1
                
                area = (i - i_left - 1) * heights[i_pop]
                max_area = max(max_area, area)
            
            idx_stack.append(i)
        
        return max_area

