#!/usr/bin/python3

'''
611. Knight Shortest Path
Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, find the shortest path to a destination position, return the length of the route.
Return -1 if knight can not reached.

Clarification
If the knight is at (x, y), he can get to the following positions in one step:

(x + 1, y + 2)
(x + 1, y - 2)
(x - 1, y + 2)
(x - 1, y - 2)
(x + 2, y + 1)
(x + 2, y - 1)
(x - 2, y + 1)
(x - 2, y - 1)

Example
[[0,0,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 2

[[0,1,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 6

[[0,1,0],
 [0,0,1],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return -1


Author: Yuan Li
Date: 6/22/2018 
Difficulty: Medium
'''

"""
Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
"""

class Solution:
    """
    @param grid: a chessboard included 0 (false) and 1 (true)
    @param source: a point
    @param destination: a point
    @return: the shortest path 
    """
    def shortestPath(self, grid, source, destination):
        # write your code here
        if grid == None or len(grid) == 0 or len(grid[0]) == 0:
            return -1
           
        length = 0 
        if source == destination:
            return length
            
        queue = [source]
        dx = [1, 1, -1, -1, 2, 2, -2, -2]
        dy = [2, -2, 2, -2, 1, -1, 1, -1]
        while queue:
            length += 1
            for i in range(len(queue)):
                currPos = queue.pop(0)
                for d in range(len(dx)):
                    nextPos = Point(currPos.x + dx[d], currPos.y + dy[d])
                    
                    if self.isValid(grid, nextPos):
                        if nextPos.x == destination.x and nextPos.y == destination.y:
                            return length
                        
                        grid[nextPos.x][nextPos.y] = 1
                        queue.append(nextPos)
                        
        return -1
                        
    def isValid(self, grid, pos):
        return 0 <= pos.x < len(grid) and 0 <= pos.y < len(grid[0]) \
        and grid[pos.x][pos.y] == 0
        