#!/usr/bin/python3

'''
601. Flatten 2D Vector

Implement an iterator to flatten a 2d vector.

Example
Example 1:

Input:[[1,2],[3],[4,5,6]]
Output:[1,2,3,4,5,6]

Example 2:

Input:[[7,9],[5]]
Output:[7,9,5]


Author: Yuan Li
Date: 2/28/2019 
Difficulty: Medium
'''

class Vector2D(object):

    # @param vec2d {List[List[int]]}
    def __init__(self, vec2d):
        # Initialize your data structure here
        self.vec2d = vec2d
        self.next_elem = None
        self.row = 0
        self.col = -1
        
    # @return {int} a next element
    def next(self):
        # Write your code here
        if self.next_elem is None:
            self.hasNext()
        
        next_elem = self.next_elem
        self.next_elem = None
        
        return next_elem
            
    # @return {boolean} true if it has next element
    # or false
    def hasNext(self):
        # Write your code here
        if self.next_elem:
            return True
            
        self.col += 1    
        while self.row < len(self.vec2d) and self.col >= len(self.vec2d[self.row]):
            self.row += 1
            self.col = 0
            
        if self.row < len(self.vec2d) and self.col < len(self.vec2d[self.row]):
            self.next_elem = self.vec2d[self.row][self.col]
            return True
            
        return False

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())

