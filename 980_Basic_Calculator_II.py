#!/usr/bin/python3

'''
980. Basic Calculator II
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Example
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Notice
Do not use the eval built-in library function.


Author: Yuan Li
Date: 8/16/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: the given expression
    @return: the result of expression
    """
    def calculate(self, s):
        # Write your code here
        stk = []
        
        i = 0
        while i < len(s) and s[i] not in {'+', '-', '*', '/'}:
            i += 1
            
        stk.append(int(s[:i]))

        while i < len(s):
            num, end = self.getNum(s, i)

            if s[i] == '+':
                stk.append(num)
                
            elif s[i] == '-':
                stk.append(-num)
            
            elif s[i] == '*':
                topNum = stk.pop()
                stk.append(topNum * num)
            
            else:
                topNum = stk.pop()
                stk.append(int(topNum / num))
            
            i = end
            
        res = 0    
        while stk:
            res += stk.pop()
            
        return res
                
    def getNum(self, s, idx):
        end = idx + 1
        while end < len(s) and s[end] not in {'+', '-', '*', '/'}:
            end += 1
 
        return int(s[idx+1:end]), end
