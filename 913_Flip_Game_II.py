#!/usr/bin/python3

'''
913. Flip Game II

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example
Given s = "++++", return true.

Explanation:
The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Challenge
Derive your algorithm's runtime complexity.

Author: Yuan Li
Date: 2/17/2019 
Difficulty: Medium
'''

class Solution:
    """
    @param s: the given string
    @return: if the starting player can guarantee a win
    """
    def canWin(self, s):
        # write your code here
        return self.dfs(s, {})
    
    def dfs(self, s, mem):
        if s in mem:
            return mem[s]
    
        for i in range(len(s) - 1):
            # To win:
            # 1. starting player must have a "++" to flip
            if s[i:i+2] != "++":
                continue
            
            # 2. second player must have no way to win
            if not self.dfs(s[:i] + "--" + s[i+2:], mem):
                mem[s] = True
                return True
    
        mem[s] = False    
        return False

