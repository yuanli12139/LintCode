#!/usr/bin/python3

'''
828. Word Pattern
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Example
Given pattern = "abba", str = "dog cat cat dog", return true.
Given pattern = "abba", str = "dog cat cat fish", return false.
Given pattern = "aaaa", str = "dog cat cat dog", return false.
Given pattern = "abba", str = "dog dog dog dog", return false.


Author: Yuan Li
Date: 6/26/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param pattern: a string, denote pattern string
    @param str: a string, denote matching string
    @return: an boolean, denote whether the pattern string and the matching string match or not
    """
    def wordPattern(self, pattern, str):
        # write your code here
        words = str.split(" ")
        if len(words) != len(pattern):
            return False
        
        table = {}
        for p, w in zip(pattern, words):
            if p not in table and w not in table.values(): 
                table[p] = w
                continue
                
            if p not in table or table[p] != w:
                return False
                
        return True
        