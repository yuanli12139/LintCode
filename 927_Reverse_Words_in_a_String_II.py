#!/usr/bin/python3

'''
927. Reverse Words in a String II
Given an input character array, reverse the array word by word. A word is defined as a sequence of non-space characters.

The input character array does not contain leading or trailing spaces and the words are always separated by a single space.

Example
Given s = "the sky is blue",
after reversing : "blue is sky the"

Challenge
Could you do it in-place without allocating extra space?


Author: Yuan Li
Date: 8/7/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param str: a string
    @return: return a string
    """
    def reverseWords(self, str):
        # write your code here
        str = self.reverseAll(str)
    
        i, j = 0, 0
        while j <= len(str):
            if (j < len(str) and str[j] != ' '):
                j += 1
                continue
            
            str = str[:i] + self.reverseAll(str[i:j]) + str[j:]
            j += 1
            i = j
            
        return str
    
    def reverseAll(self, str):
        i, j = 0, len(str) - 1
        while i < j:
            temp = str[i]
            str = str[:i] + str[j] + str[i+1:]
            str = str[:j] + temp + str[j+1:]
            i += 1
            j -= 1
            
        return str
