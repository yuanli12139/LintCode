#!/usr/bin/python3

'''
1479. Can Reach The Endpoint
Given a map size of m*n, 1 means space, 0 means obstacle, 9 means the endpoint. You start at (0,0) and return whether you can reach the endpoint.

Example
Input:[[1,1,1],[1,1,1],[1,1,9]]
Output:true


Author: Yuan Li
Date: 10/16/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param map: the map
    @return: can you reach the endpoint
    """
    def reachEndpoint(self, map):
        # Write your code here
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        
        q = [(0, 0)]
        map[0][0] = -map[0][0] # visited
        while q:
            r, c = q.pop(0)
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                if self.valid(nr, nc, map):
                    if abs(map[nr][nc]) == 9:
                        return True
                    
                    map[nr][nc] = -map[nr][nc] # visited
                    q.append((nr, nc))
                    
        return False
                
    def valid(self, r, c, map):
        return 0 <= r < len(map) and 0 <= c < len(map[0]) and map[r][c] > 0

