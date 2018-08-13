#!/usr/bin/python3

'''
53. Reverse Words in a String
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification
What constitutes a word?
A sequence of non-space characters constitutes a word.

Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.

How about multiple spaces between two words?
Reduce them to a single space in the reversed string.


Author: Yuan Li
Date: 8/13/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param: s: A string
    @return: A string
    """
    def reverseWords(self, s):
        # write your code here
        res = ''
        
        start = 0
        while start < len(s):
            if s[start] != ' ':
                break
            
            start += 1
        
        wordList = []
        end = start + 1
        while end < len(s):
            if s[end] == ' ':
                if s[end-1] != ' ':
                    wordList.append(s[start:end])
                
                start = end + 1
            
            if end == len(s) - 1:
                wordList.append(s[start:])
        
            end += 1
       
        while wordList:
            res += wordList.pop() + ' '
            
        return res[:-1]
