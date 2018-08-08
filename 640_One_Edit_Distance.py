#!/usr/bin/python3

'''
640. One Edit Distance
Given two strings S and T, determine if they are both one edit distance apart.

Example
Given s = "aDb", t = "adb"
return true


Author: Yuan Li
Date: 8/7/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: a string
    @param t: a string
    @return: true if they are both one edit distance apart or false
    """
    def isOneEditDistance(self, s, t):
        # write your code here
        if (abs(len(s) - len(t)) > 1):
            return False
            
        if (len(s) == len(t)):
            cntNE = 0
            for cs, ct in zip(s, t):
                cntNE += not cs == ct

                if cntNE > 1:
                    return False
                    
            return cntNE == 1
            
        if (len(s) > len(t)):
            return self.helper(s, t)
        
        return self.helper(t, s)
            
    def helper(self, s, t):
        i, j = 0, 0
        while i < len(s) and j < len(t):
            if i - j > 1:
                return False
            
            if s[i] == t[j]:
                i += 1
                j += 1
                
            else:
                i += 1
            
        return True     
