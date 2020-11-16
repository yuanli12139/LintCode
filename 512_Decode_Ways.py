#!/usr/bin/python3

'''
512. Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as AB (1 2) or L (12).

Example 2:
Input: "10"
Output: 1

Notice
we can't decode an empty string. So you should return 0 if the message is empty.
The length of message n ≤ 100


Author: Yuan Li
Date: 11/15/2020
Difficulty: Medium
'''

# dynamic programming
# time: O(n)
# space: O(1)
class Solution:
    """
    @param s: a string,  encoded message
    @return: an integer, the number of ways decoding
    """

    def numDecodings(self, s):
        # write your code here
        if not s or s[0] == '0':
            return 0

        if len(s) == 1:
            return 1

        dp1 = 1
        dp2 = 1

        for i in range(1, len(s)):
            dp = 0
            if not self.isValid(s[i], None) and not self.isValid(s[i], s[i-1]):
                return 0

            if self.isValid(s[i], None):
                dp += dp1

            if self.isValid(s[i], s[i-1]):
                dp += dp2

            dp2 = dp1
            dp1 = dp

        return dp1

    def isValid(self, c, c1):
        if not c1:
            return c != '0'

        n = int(c1) * 10 + int(c)
        return n >= 10 and n <= 26
