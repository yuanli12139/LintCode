#!/usr/bin/python3

'''
844. Backspace String Compare (LeetCode)
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:
1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.

Follow up:
Can you solve it in O(N) time and O(1) space?


Author: Yuan Li
Date: 9/12/2018 
Difficulty: Easy
'''

class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        i = len(S) - 1    
        j = len(T) - 1    

        cntS, cntT = 0, 0
        while i >= 0 or j >= 0:
            # i stops at a unresolved char or -1 ("")
            while i >= 0:
                if S[i] == '#': 
                    cntS += 1
                    i -= 1
                elif cntS > 0:
                    cntS -= 1
                    i -= 1
                else:
                    break

            # j stops at a unresolved char or -1 ("")
            while j >= 0: 
                if T[j] == '#':
                    cntT += 1
                    j -= 1
                elif cntT > 0:
                    cntT -= 1
                    j -= 1
                else:
                    break  
            
            # "abc##" <->  ""
            #  i          j
            if (i >= 0 and j < 0) or (i < 0 and j >= 0):
                return False
             
            # "dabc--" <->  "adbc--"
            #   i             j
            if i >= 0 and j >= 0 and S[i] != T[j]:
                return False

            # "aabc--" <->  "aabc--"
            #   i             j
            i -= 1
            j -= 1

        return True
