#!/usr/bin/python3

'''
644. Strobogrammatic Number
A mirror number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is mirror. The number is represented as a string.

Example
For example, the numbers "69", "88", and "818" are all mirror numbers.
Given num = "69" return true
Given num = "68" return false


Author: Yuan Li
Date: 11/17/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param num: a string
    @return: true if a number is strobogrammatic or false
    """
    def isStrobogrammatic(self, num):
        # write your code here
        if not num:
            return False
        
        table = {'6':'9', '9':'6', '8':'8', '0':'0', '1':'1'}
        
        left, right = 0, len(num) - 1
        while left <= right:
            if num[left] not in table or table[num[left]] != num[right]:
                return False
            
            left += 1
            right -= 1
          
        return True

