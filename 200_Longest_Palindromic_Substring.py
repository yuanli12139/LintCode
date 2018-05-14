#!/usr/bin/python3

'''
200. Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Example
Given the string = "abcdzdcab", return "cdzdc".

Challenge
O(n^2) time is acceptable. Can you do it in O(n) time.


Author: Yuan Li
Date: 5/13/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: input string
    @return: the longest palindromic substring
    """
    def longestPalindrome(self, s):
        # write your code here
        if s == None or s == "":
            return ""
        
        start = 0 
        longest = 0
        for i in range(len(s)):
            length = self.findLongestPalindrome(s, i, i)
            if length > longest:
                longest = length
                start = i - int(longest / 2)
                
            length = self.findLongestPalindrome(s, i, i+1)
            if length > longest:
                longest = length
                start = i - int(longest / 2) + 1

        return s[start:start+longest]
            
        
    def findLongestPalindrome(self, s, left, right):
        length = 0
        while left >= 0 and right < len(s): 
            if s[left] == s[right]:
                if left == right:
                    length += 1
                else:
                    length += 2
                left -= 1
                right += 1
            else:
                break
            
        return length
        