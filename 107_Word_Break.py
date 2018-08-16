#!/usr/bin/python3

'''
107. Word Break
Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.

Example
Given s = "lintcode", dict = ["lint", "code"].

Return true because "lintcode" can be break as "lint code".


Author: Yuan Li
Date: 8/15/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param: s: A string
    @param: dict: A dictionary of words dict
    @return: A boolean
    """
    def wordBreak(self, s, dict):
        # write your code here
        if not s:
            return True
            
        dp = [False] * (len(s) + 1)
        
        dp[0] = True
        for i in range(len(s)):
            if dp[i] == False:
                continue
            
            for word in dict:
                end = i + len(word)
                
                if s[i:end] == word:
                    dp[end] = True
        
        return dp[len(s)]
