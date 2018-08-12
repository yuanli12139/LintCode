#!/usr/bin/python3

'''
667. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example
Given s = "bbbab" return 4
One possible longest palindromic subsequence is "bbbb".


Author: Yuan Li
Date: 8/11/2018 
Difficulty: Medium
'''

# Time: O(n^2)
# Space: O(n^2)
class Solution:
    """
    @param s: the maximum length of s is 1000
    @return: the longest palindromic subsequence's length
    """
    def longestPalindromeSubseq(self, s):
        # write your code here
        n = len(s)
        
        if n == 0:
            return 0
            
        dp = [[0 for _ in range(n)] for _ in range(n)]
        
        for l in range(1, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                
                if i == j:
                    dp[i][j] = 1
                    continue
                
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
                    
        return dp[0][n-1]


# Time: O(n^2)
# Space: O(n)
class Solution:
    """
    @param s: the maximum length of s is 1000
    @return: the longest palindromic subsequence's length
    """
    def longestPalindromeSubseq(self, s):
        # write your code here
        n = len(s)
        
        if n == 0:
            return 0
            
        dp0 = [0 for _ in range(n)] # solutions of l
        dp1 = [0 for _ in range(n)] # solutions of l - 1
        dp2 = [0 for _ in range(n)] # solutions of l - 2
        
        for l in range(1, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                
                if i == j:
                    dp0[i] = 1
                    continue
                
                if s[i] == s[j]:
                    dp0[i] = dp2[i+1] + 2
                
                else:
                    dp0[i] = max(dp1[i+1], dp1[i])
                    
            dp2 = dp1[:]
            dp1 = dp0[:]
                    
        return dp0[0]
