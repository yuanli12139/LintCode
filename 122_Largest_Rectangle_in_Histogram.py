#!/usr/bin/python3

'''
122. Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Picture
https://lintcode-media.s3.amazonaws.com/problem/histogram1.png

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Picture
https://lintcode-media.s3.amazonaws.com/problem/histogram_area.png

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example
Given height = [2,1,5,6,2,3],
return 10.


Author: Yuan Li
Date: 11/14/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param height: A list of integer
    @return: The area of largest rectangle in the histogram
    """
    def largestRectangleArea(self, height):
        # write your code here
        max_area = 0
        
        idx_stack = [] # monotonous stack
        for i, h in enumerate(height + [0]): # add 0 to ensure everything gets popped out
            while idx_stack and height[idx_stack[-1]] >= h:
                i_pop = idx_stack.pop()
                i_left = idx_stack[-1] if idx_stack else -1
                
                area = (i - i_left - 1) * height[i_pop]
                max_area = max(max_area, area)
                
            idx_stack.append(i)

        return max_area

