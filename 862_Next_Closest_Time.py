#!/usr/bin/python3

'''
862. Next Closest Time
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example
Given time = "19:34", return "19:39".

Explanation: 
The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Given time = "23:59", return "22:22".

Explanation: 
The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.


Author: Yuan Li
Date: 8/5/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param time: the given time
    @return: the next closest time
    """
    def nextClosestTime(self, time):
        # write your code here
        hands = [4, 3, 1, 0]
        
        minDigit = '9'
        for i in hands:
            if time[i] < minDigit:
                minDigit = time[i]
        
        for i in hands:
            minGreater = chr(ord('9') + 1) # ':' > '9' in ascii
            for j in hands:
                if i == j:
                    continue
                
                if time[i] < time[j] < minGreater:
                    minGreater = time[j]
            
            if minGreater == chr(ord('9') + 1):
                continue
            
            # found minGreater
            next_time = time[:i] + minGreater + time[i+1:]
            for k in range(i + 1, len(next_time)):
                if next_time[k] != ':':
                    next_time = next_time[:k] + minDigit + next_time[k+1:]                
            
            if self.isValid(next_time):
                return next_time
                
        # no valid, return the time with the min digit
        next_time = time
        for i in hands:
            next_time = next_time[:i] + minDigit + next_time[i+1:]
            
        return next_time
        
    def isValid(self, time):
        hh = int(time[0:2])
        mm = int(time[3:5])
        
        return 0 <= hh < 24 and 0 <= mm < 60 
        