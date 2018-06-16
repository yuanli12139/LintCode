#!/usr/bin/python3

'''
423. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

Example
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


Author: Yuan Li
Date: 6/16/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param s: A string
    @return: whether the string is a valid parentheses
    """
    def isValidParentheses(self, s):
        # write your code here
        stack = []
        parentheses_pair = {')': '(', ']': '[', '}': '{'}
        
        for c in s:
            if not stack:
                stack.append(c)
                continue
            
            if c in parentheses_pair and parentheses_pair[c] == stack[-1]:
                stack.pop()
                
            else:
                stack.append(c)
                
        if stack:
            return False
            
        return True
        