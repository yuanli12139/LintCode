#!/usr/bin/python3

'''
433. Number of Islands
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.

Example
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.


Author: Yuan Li
Date: 6/22/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    def numIslands(self, grid):
        # write your code here
        if grid == None or len(grid) == 0 or len(grid[0]) == 0:
            return 0
            
        islands = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c]:
                    grid[r][c] = 0
                    self.bfs(grid, r, c)
                    islands += 1
                    
        return islands
        
    def bfs(self, grid, r, c):
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        
        queue = [[r, c]]
        while queue:
            for i in range(len(queue)):
                currPos = queue.pop(0)
                for d in range(4):
                    nextPos = [currPos[0] + dr[d], currPos[1] + dc[d]]
                    if self.isValid(grid, nextPos) and grid[nextPos[0]][nextPos[1]]:
                        grid[nextPos[0]][nextPos[1]] = 0
                        queue.append(nextPos)
                        
    def isValid(self, grid, pos):
        return 0 <= pos[0] < len(grid) and 0 <= pos[1] < len(grid[0]) 
    