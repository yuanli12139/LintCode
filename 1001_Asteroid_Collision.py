#!/usr/bin/python3

'''
1001. Asteroid Collision
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example
Input:
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation:
The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Input:
asteroids = [10, 2, -5]
Output: [10]
Explanation:
The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Notice
The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000]..


Author: Yuan Li
Date: 8/11/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param asteroids: a list of integers
    @return: return a list of integers
    """
    def asteroidCollision(self, asteroids):
        # write your code here
        stk = []
        for asteroid in asteroids:
            if len(stk) == 0 or (stk[-1] < 0 and asteroid > 0) or stk[-1] * asteroid > 0:
                stk.append(asteroid)
                continue
            
            top = stk[-1]    
            while len(stk) > 0 and stk[-1] > 0 and asteroid < 0:
                top = stk.pop()
                
                if top + asteroid == 0: # same size
                    break
                
                if abs(top) > abs(asteroid):
                    stk.append(top)
                    break
            
            if abs(top) < abs(asteroid):  
                stk.append(asteroid)
             
        return stk
