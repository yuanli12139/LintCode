#!/usr/bin/python3

'''
582. Word Break II
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].

A solution is ["lint code", "lint co de"].


Author: Yuan Li
Date: 9/9/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param: s: A string
    @param: wordDict: A set of words.
    @return: All possible sentences.
    """
    def __init__(self):
        self._memo = {}
    
    def wordBreak(self, s, wordDict):
        # write your code here
        return self.dfs(s, wordDict)
        
    def dfs(self, s, wordDict):
        res = []
        if not s:
            return res
        
        if s in self._memo:
            return self._memo[s]
        
        # s is a word    
        if s in wordDict:
            res.append(s)

        # break word
        for l in range(1, len(s)):
            prefix = s[:l]
            if prefix not in wordDict:
                continue
            
            suffix = s[l:]
            breaks = self.dfs(suffix, wordDict)
            
            # add "lint" to ["code", "co de"]
            for b in breaks:
                res.append(prefix + ' ' + b)
                
        self._memo[s] = res
                
        return res
