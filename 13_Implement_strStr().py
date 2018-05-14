#!/usr/bin/python3

'''
13. Implement strStr()
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n^2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Author: Yuan Li
Date: 5/12/2018 
'''

class Solution:
    """
    @param: source: source string to be scanned.
    @param: target: target string containing the sequence of characters to match
    @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
    """
    def strStr(self, source, target):
        # write your code here
        if source == None or target == None:
            return -1

        elif len(source) >= len(target):
            for i in range(len(source)-len(target)+1):
                sub_s = source[i:i+len(target)]
                if sub_s == target:
                    return i
        return -1 
