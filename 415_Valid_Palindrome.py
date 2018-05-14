#!/usr/bin/python3

'''
415. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example
"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Challenge
O(n) time without extra memory.


Author: Yuan Li
Date: 5/12/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param s: A string
    @return: Whether the string is a valid palindrome
    """
    def isPalindrome(self, s):
        # write your code here
        valid = [c for c in s.lower() if c.isalpha() or c.isdigit()]
        for i in range(int(len(valid)/2)):
            ch_l = valid[i]
            ch_r = valid[len(valid)-1-i]
            
            if ch_l != ch_r:
                return False
        return True
