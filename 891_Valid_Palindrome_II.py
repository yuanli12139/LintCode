#!/usr/bin/python3

'''
891. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example
Given s = "aba" return true
Given s = "abca" return true // delete c


Author: Yuan Li
Date: 6/12/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param s: a string
    @return: nothing
    """
    def validPalindrome(self, s):
        # Write your code here
        start = 0
        end = len(s) - 1
        
        while start < end:
            if s[start] != s[end]:
                break
            start += 1
            end -= 1
            
        if start < end:
            return self.isSubPalindrome(s, start+1, end) or \
            self.isSubPalindrome(s, start, end-1) 
            
        return True
        
    def isSubPalindrome(self, s, start, end):
        while start <= end:
            if s[start] != s[end]:
                return False
            
            start += 1
            end -= 1
            
        return True
        