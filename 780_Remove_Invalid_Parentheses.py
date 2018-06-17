#!/usr/bin/python3

'''
780. Remove Invalid Parentheses
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Example
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]


Author: Yuan Li
Date: 6/17/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param s: The input string
    @return: Return all possible results
    """
    def removeInvalidParentheses(self, s):
        # Write your code here
        res = []
        res = self.helper(res, s, len(s))
        
        if res == []:
            return [""]
        return res
        
    def helper(self, res, s, n):
        if n == 0:
            return res
        
        if self.isValidParentheses(s):
            if s not in res:
                res.append(s)
            return res
         
        l, r, pr = 0, 0, []
        for i in range(n):
            l += s[i] == '('
            if s[i] == ')':
                r += 1
                pr.append(i)
            
            if l < r:
                for j in pr:
                    subs = s[:j] + s[j+1:] 
                    res = self.helper(res, subs, n - 1)
                break

        l, r, pl = 0, 0, []
        for i in range(n):
            if s[n - 1 - i] == '(':
                l += 1
                pl.append(n - 1 - i)
            r += s[n - 1 - i] == ')'
            
            if l > r:
                for j in pl:
                    subs = s[:j] + s[j+1:]
                    res = self.helper(res, subs, n - 1)
                break
        
        return res
        
    def isValidParentheses(self, s):
        if not s:
            return True
        
        stack = []
        
        for c in s:
            if not stack: 
                if c == '(' or c == ')':
                    stack.append(c)
                continue
            
            if c == ')' and stack[-1] == '(':
                stack.pop()
                
            elif c == '(' or c == ')':
                stack.append(c)
                
        if stack:
            return False
            
        return True
