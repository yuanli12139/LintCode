#!/usr/bin/python3

'''
1710. Beautiful Array
For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A. (It is guaranteed that one exists.)

Example
Example 1:

Input: N = 4
Output: [1,3,2,4]
Example 2:

Input: N = 5
Output: [1,5,3,2,4]
Notice
1 <= N <= 1000


Author: Yuan Li
Date: 1/18/2021 
Difficulty: Medium
'''

class Solution:
    """
    @param N: an integer
    @return: return any beautiful array A
    """
    def __init__(self):
        self.mem = {}
    
    def beautifulArray(self, N):
        # write your code here.
        self.mem = {1: [1]}
        return self.helper(N)
        
    def helper(self, N):
        if N in self.mem:
            return self.mem[N]
        
        odds = self.helper((N+1)//2)
        evens = self.helper(N//2)
        self.mem[N] = [2*x-1 for x in odds] + [2*x for x in evens]
        return self.mem[N]
