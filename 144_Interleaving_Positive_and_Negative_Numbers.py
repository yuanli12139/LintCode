#!/usr/bin/python3

'''
144. Interleaving Positive and Negative Numbers
Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.

Example
Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other reasonable answer.

Challenge
Do it in-place and without extra memory.


Author: Yuan Li
Date: 6/17/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param: A: An integer array.
    @return: nothing
    """
    def rerange(self, A):
        # write your code here
        if A == None or len(A) <= 1:
            return
        
        left, right = 0, len(A) - 1
        while left <= right:
            while left <= right and A[left] < 0:
                left += 1
                
            while left <= right and A[right] > 0:
                right -= 1
                
            if left <= right:
                A[left], A[right] = A[right], A[left]
                left += 1
                right -= 1

        if left < len(A) / 2:
            for i in range(0, left, 2):
                A[i], A[len(A) - 2 - i] = A[len(A) - 2 - i], A[i]
                
        elif left == len(A) / 2:
            for i in range(1, left, 2):
                A[i], A[len(A) - 1 - i] = A[len(A) - 1 - i], A[i]
                
        else:
            for i in range(1, left, 2):
                A[i], A[len(A) - i] = A[len(A) - i], A[i]
        