#!/usr/bin/python3

'''
171. Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].

Challenge
What is Anagram?

Two strings are anagram if they can be the same after change the order of characters.

Notice
All inputs will be in lower-case


Author: Yuan Li
Date: 8/10/2018 
Difficulty: Medium
'''

# sort - O(nklog(k))
class Solution:
    """
    @param strs: A list of strings
    @return: A list of strings
    """
    def anagrams(self, strs):
        # write your code here
        sorted2strs = {}
        for s in strs:
            sorted_str = ''.join(sorted(s))
            if sorted_str not in sorted2strs:
                sorted2strs[sorted_str] = [s]
            else:
                sorted2strs[sorted_str].append(s)
                
        res = []
        for _, str_list in sorted2strs.items():
            if len(str_list) > 1:
                res += str_list
                
        return res


# hash code - O(nk)
class Solution:
    """
    @param strs: A list of strings
    @return: A list of strings
    """
    def anagrams(self, strs):
        # write your code here
        prime_nums = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, \
                        47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
        
        hash2strs = {}
        for s in strs:
            h = self.getHash(s, prime_nums)
            # if h not in hash2strs:
            #     hash2strs[h] = [s]
            # else:
            #     hash2strs[h].append(s)
            hash2strs.setdefault(h, []).append(s)
                
        res = []
        for _, str_list in hash2strs.items():
            if len(str_list) > 1:
                res += str_list
                
        return res
        
    def getHash(self, s, prime_nums):
        h = 1
        for c in s:
            h *= prime_nums[ord(c) - ord('a')]
            
        return h

