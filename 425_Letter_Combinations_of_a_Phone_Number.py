#!/usr/bin/python3

'''
425. Letter Combinations of a Phone Number
Given a digit string excluded 01, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Picture
https://lintcode-media.s3.amazonaws.com/problem/200px-Telephone-keypad2.svg.png

Although the above answer is in lexicographical order, your answer could be in any order you want.

Example
Given "23"

Return ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]


Author: Yuan Li
Date: 8/4/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param digits: A digital string
    @return: all posible letter combinations
    """
    def letterCombinations(self, digits):
        # write your code here
        res = []
        comb = ""
        
        if not digits:
            return res 

        digit2letters = {'2': "abc", '3': "def", '4': "ghi", '5': "jkl", '6': "mno", \
                            '7': "pqrs", '8': "tuv", '9': "wxyz"}
                
        self.dfs(digits, comb, digit2letters, res)
        
        return res
        
    def dfs(self, digits, comb, digit2letters, res):
        if len(comb) == len(digits):
            res.append(comb)
            return
        
        digit = digits[len(comb)]
        for letter in digit2letters[digit]:
            comb += letter
            self.dfs(digits, comb, digit2letters, res)
            comb = comb[:-1]
                