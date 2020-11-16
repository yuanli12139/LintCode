#!/usr/bin/python3

'''
364. Trapping Rain Water II
Given n x m non-negative integers representing an elevation map 2d where the area of each cell is 1 x 1, compute how much water it is able to trap after raining.

Picture
https://lintcode-media.s3.amazonaws.com/problem/trapping-rain-water-ii.jpg

Example
Given 5*4 matrix

[12,13,0,12]
[13,4,13,12]
[13,8,10,12]
[12,13,12,12]
[13,13,13,13]
return 14.


Author: Yuan Li
Date: 11/12/2018 
Difficulty: Hard
'''

import heapq

class Solution:
    """
    @param heights: a matrix of integers
    @return: an integer
    """
    def __init__(self):
        self.borders = []
        self.visited = set()
    
    def trapRainWater(self, heights):
        # write your code here
        if not heights:
            return 0
        
        # initialize heap with borders
        n, m = len(heights), len(heights[0])
        for r in range(n):
            self.add(heights[r][0], r, 0)
            self.add(heights[r][m-1], r, m - 1)
            
        for c in range(1, m - 1):
            self.add(heights[0][c], 0, c)
            self.add(heights[n-1][c], n - 1, c)
            
        # dig in
        water = 0
        while self.borders:
            h, r, c = heapq.heappop(self.borders)
            for nr, nc in self.adjcent(r, c, n, m):
                water += max(0, h - heights[nr][nc])
                self.add(max(h, heights[nr][nc]), nr, nc)
            
        return water    
            
    def add(self, height, row, col):
        heapq.heappush(self.borders, (height, row, col))
        self.visited.add((row, col))
        
    def adjcent(self, row, col, length, width):
        adj = []
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr = row + dr
            nc = col + dc
            if 0 <= nr < length and 0 <= nc < width and (nr, nc) not in self.visited:
                adj.append((nr, nc))
                
        return adj

