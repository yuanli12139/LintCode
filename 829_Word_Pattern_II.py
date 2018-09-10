#!/usr/bin/python3

'''
829. Word Pattern II
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.(i.e if a corresponds to s, then b cannot correspond to s. For example, given pattern = "ab", str = "ss", return false.)

Example
Given pattern = "abab", str = "redblueredblue", return true.
Given pattern = "aaaa", str = "asdasdasdasd", return true.
Given pattern = "aabb", str = "xyzabcxzyabc", return false.

Notice
You may assume both pattern and str contains only lowercase letters.


Author: Yuan Li
Date: 6/27/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param pattern: a string,denote pattern string
    @param str: a string, denote matching string
    @return: a boolean
    """
    def wordPatternMatch(self, pattern, str):
        # write your code here
        table = {}
        return self.DFSHelper(pattern, 0, str, 0, table)

    def DFSHelper(self, pattern, p, str, r, table):
        if p == len(pattern) and r == len(str): return True
        if p == len(pattern) or r == len(str): return False
        
        c = pattern[p]
        for i in range(r, len(str)):
            substr = str[r:i+1]
            if c in table and table[c] == substr:
                if self.DFSHelper(pattern, p+1, str, i+1, table):
                    return True
                    
            elif c not in table:
                if substr not in table.values():
                    table[c] = substr
                    
                    if self.DFSHelper(pattern, p+1, str, i+1, table):
                        return True
                        
                    del table[c]
                    
        return False


'''
Date: 9/9/2018
'''

class Solution:
    """
    @param pattern: a string,denote pattern string
    @param str: a string, denote matching string
    @return: a boolean
    """
    def __init__(self):
        self._pattern_str = {}
        self._mapped_str = set()
    
    def wordPatternMatch(self, pattern, str):
        # write your code here
        return self.dfs(pattern, str)
        
    def dfs(self, pattern, str):
        if not pattern:
            return not str
            
        p = pattern[0]
        if p in self._pattern_str:
            match = self._pattern_str[p]
            if str[:len(match)] != match:
                return False
                
            remain_pattern = pattern[1:]
            remain_str = str[len(match):]
            
            return self.dfs(remain_pattern, remain_str)
            
        for i in range(1, len(str) + 1):
            s = str[:i]
            if s in self._mapped_str:
                continue
            
            self._pattern_str[p] = s
            self._mapped_str.add(s)
            
            remain_pattern = pattern[1:]
            remain_str = str[i:]
            
            if self.dfs(remain_pattern, remain_str):
                return True
                
            # del self._pattern_str[p] # key exsits for sure
            self._pattern_str.pop(p, None)
            self._mapped_str.remove(s)
            
        return False
  