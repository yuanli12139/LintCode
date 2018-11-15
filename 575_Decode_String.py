#!/usr/bin/python3

'''
575. Decode String
Given an expression s includes numbers, letters and brackets. Number represents the number of repetitions inside the brackets(can be a string or another expression)．Please expand expression to be a string.

Example
s = abc3[a] return abcaaa
s = 3[abc] return abcabcabc
s = 4[ac]dy, return acacacacdy
s = 3[2[ad]3[pf]]xyz, return adadpfpfpfadadpfpfpfadadpfpfpfxyz

Challenge
Can you do it without recursion?


Author: Yuan Li
Date: 11/14/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: an expression includes numbers, letters and brackets
    @return: a string
    """
    def expressionExpand(self, s):
        # write your code here
        stk = []
        for c in s:
            if c != ']':
                stk.append(c)
                continue
            
            chs = []
            while stk[-1] != '[':
                chs.append(stk.pop())
                
            stk.pop() # skip '['
            
            repeats = ""
            while stk and stk[-1].isdigit():
                repeats += stk.pop()
            
            expanded = ''.join(chs[::-1] * int(repeats[::-1]))
            stk.append(expanded)
        
        return ''.join(stk)

