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
            