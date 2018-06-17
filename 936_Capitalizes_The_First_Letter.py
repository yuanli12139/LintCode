#!/usr/bin/python3

'''
936. Capitalizes The First Letter
Given a sentence of English, update the first letter of each word to uppercase.

Example
Given s = "i want to get an accepted", return "I Want To Get An Accepted".


Author: Yuan Li
Date: 6/16/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: a string
    @return: a string after capitalizes the first letter
    """
    def capitalizesFirst(self, s):
        # Write your code here
        s = s[0].upper() + s[1:]
        
        for i in range(1, len(s) - 1):
            if s[i] == ' ':
                s = s[:i+1] + s[i+1].upper() + s[i+2:]
                
        return s
        