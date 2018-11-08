#!/usr/bin/python3

'''
655. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Example
Given num1 = "123", num2 = "45"
return "168"

Notice
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


Author: Yuan Li
Date: 11/7/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param num1: a non-negative integers
    @param num2: a non-negative integers
    @return: return sum of num1 and num2
    """
    def addStrings(self, num1, num2):
        # write your code here
        l1, l2 = len(num1), len(num2)
        
        max_num = num1 if l1 > l2 else num2
        
        carry = 0
        res = ""
        
        for i in range(len(max_num)):
            if i < min(l1, l2):
                s = int(num1[l1-i-1]) + int(num2[l2-i-1]) + carry
            else:
               	s = int(max_num[len(max_num)-i-1]) + carry
            
            res += str(s % 10)
            carry = s >= 10
                       
        if carry:
            res += "1"
                       
        return res[::-1]

