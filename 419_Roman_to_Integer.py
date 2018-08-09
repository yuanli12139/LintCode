#!/usr/bin/python3

'''
419. Roman to Integer
Given a roman numeral, convert it to an integer.

The answer is guaranteed to be within the range from 1 to 3999.

Example
IV -> 4

XII -> 12

XXI -> 21

XCIX -> 99

Clarification
What is Roman Numeral?

https://en.wikipedia.org/wiki/Roman_numerals
https://zh.wikipedia.org/wiki/罗马数字
http://baike.baidu.com/view/42061.htm


Author: Yuan Li
Date: 8/8/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: Roman representation
    @return: an integer
    """
    def romanToInt(self, s):
        # write your code here
        romanDict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        
        res = 0
        for i in range(len(s) - 1):
            if romanDict[s[i]] < romanDict[s[i+1]]: # IV, IX ...
                res -= romanDict[s[i]]
            else:
                res += romanDict[s[i]]
                
        res += romanDict[s[-1]]
            
        return res
            