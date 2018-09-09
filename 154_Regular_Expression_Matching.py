#!/usr/bin/python3

'''
154. Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


The function prototype should be:

bool isMatch(string s, string p)

Example
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true


Author: Yuan Li
Date: 9/9/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param s: A string 
    @param p: A string includes "." and "*"
    @return: A boolean
    """
    def __init__(self):
        self._visited = []
        self._memo = []
    
    def isMatch(self, s, p):
        # write your code here
        self._visited = [[False for _ in range(len(p))] for _ in range(len(s))]
        self._memo = [[False for _ in range(len(p))] for _ in range(len(s))]
        
        return self.dfs(s, 0, p, 0)
        
    def dfs(self, s, sIdx, p, pIdx):
        if pIdx == len(p):
            return sIdx == len(s)
            
        if sIdx == len(s):
            # the rest of p must be in _*_*_* pattern
            return self.isEmpty(p, pIdx)
            
        if self._visited[sIdx][pIdx]:
            return self._memo[sIdx][pIdx]
            
        self._visited[sIdx][pIdx] = True
        
        # _* matches either empty or a '_'
        if pIdx + 1 < len(p) and p[pIdx+1] == '*':
            match = self.dfs(s, sIdx, p, pIdx + 2) or \
                    (self.isCharMatch(s[sIdx], p[pIdx]) and self.dfs(s, sIdx + 1, p, pIdx))
        else:
            match = self.isCharMatch(s[sIdx], p[pIdx]) and self.dfs(s, sIdx + 1, p, pIdx + 1)
            
        self._memo[sIdx][pIdx] = match
        return match
            
    def isEmpty(self, p, pIdx):
        for i in range(pIdx, len(p), 2):
            if i == len(p) - 1 or p[i+1] != '*':
                return False
                
        return True
        
    def isCharMatch(self, s_char, p_char):
        return s_char == p_char or p_char == '.'
