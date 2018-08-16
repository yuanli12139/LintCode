#!/usr/bin/python3

'''
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false


Author: Yuan Li
Date: 8/15/2018 
Difficulty: Medium
'''

class Solution:
    def __init__(self):
        self.memo = {}
    
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        minLen = len(s)
        for word in wordDict:
            minLen = min(len(word), minLen)
        
        return self.helper(s, wordDict, minLen)
        
    def helper(self, s, wordDict, minLen):
        if s in self.memo:
            return self.memo[s]
        
        if not s or s in wordDict:
            self.memo[s] = True
            return True
            
        for i in range(minLen, len(s) - minLen + 1):
            right = s[i:] in wordDict
            if not right:
                continue
            
            left = self.helper(s[:i], wordDict, minLen)    
            
            if left:    
                self.memo[s] = True
                return True    
                
        self.memo[s] = False
        return False
