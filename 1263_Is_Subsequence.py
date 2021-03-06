#!/usr/bin/python3

'''
1263. Is Subsequence
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example
Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Challenge
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?


Author: Yuan Li
Date: 6/16/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: the given string s
    @param t: the given string t
    @return: check if s is subsequence of t
    """
    def isSubsequence(self, s, t):
        # Write your code here
        si, ti = 0, 0
        while si < len(s) and ti < len(t):
            if s[si] == t[ti]:
                si += 1
            
            ti += 1
            
        if not si < len(s):
            return True
        
        return False
        