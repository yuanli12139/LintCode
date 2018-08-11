#!/usr/bin/python3

'''
171. Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].

Challenge
What is Anagram?

Two strings are anagram if they can be the same after change the order of characters.

Notice
All inputs will be in lower-case


Author: Yuan Li
Date: 8/10/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param strs: A list of strings
    @return: A list of strings
    """
    def anagrams(self, strs):
        # write your code here
        sorted2strs = {}
        for s in strs:
            sorted_str = ''.join(sorted(s))
            if sorted_str not in sorted2strs:
                sorted2strs[sorted_str] = [s]
            else:
                sorted2strs[sorted_str].append(s)
                
        res = []
        for _, strs in sorted2strs.items():
            if len(strs) > 1:
                res += strs
                
        return res
