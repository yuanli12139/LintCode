#!/usr/bin/python3

'''
1335. Repeated DNA Sequences
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]


Author: Yuan Li
Date: 6/16/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param s: a string
    @return: return List[str]
    """
    def findRepeatedDnaSequences(self, s):
        # write your code here
        res = []
        hashTable = {}
        for i in range(len(s) - 9):
            sub = s[i:i+10]

            if sub in hashTable:
                hashTable[sub] += 1
                
            else:
                hashTable[sub] = 1
                
        for k in hashTable:
            if hashTable[k] > 1:
                res.append(k)
                
        return res
        