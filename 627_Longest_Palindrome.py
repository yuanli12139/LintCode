#!/usr/bin/python3

'''
627. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Example
Given s = "abccccdd" return 7

One longest palindrome that can be built is "dccaccd", whose length is 7.

Author: Yuan Li
Date: 5/13/2018 
'''

class Solution:
    """
    @param s: a string which consists of lowercase or uppercase letters
    @return: the length of the longest palindromes that can be built
    """
    def longestPalindrome(self, s):
        # write your code here
        if s == None:
            return 0
            
        dictionary = [0] * 52
        for c in s:
            if ord(c) <= 90:
                dictionary[ord(c)-65] += 1
            else:
                dictionary[ord(c)-6-65] += 1
            
        length = 0
        center_fill = False
        for n in dictionary:
            if n % 2 == 0:
                length += n
            elif not center_fill:
                length += n
                center_fill = True
            else:
                length += n - 1
                
        return length
         