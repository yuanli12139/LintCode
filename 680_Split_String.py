#!/usr/bin/python3

'''
680. Split String
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

Example
Given the string "123"
return [["1","2","3"],["12","3"],["1","23"]]


Author: Yuan Li
Date: 8/4/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param: : a string to be split
    @return: all possible split string array
    """
    def splitString(self, s):
        # write your code here
        res = []
        comb = []
    
        if s == None or len(s) == 0:
            res.append(comb)
            return res
            
        self.dfs(s, comb.copy(), 0, res)
        return res
        
    def dfs(self, s, comb, startIdx, res):
        if startIdx == len(s):
            res.append(comb)
            return
        
        for i in range(startIdx, len(s)):
            if i >= startIdx + 2:
                break
            
            comb.append(s[startIdx:i+1])
            self.dfs(s, comb.copy(), i + 1, res)
            comb.pop()
