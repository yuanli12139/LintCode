#!/usr/bin/python3

'''
65. Median of two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example
Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.

Given A=[1,2,3] and B=[4,5], the median is 3.

Challenge
The overall run time complexity should be O(log (m+n)).


Author: Yuan Li
Date: 9/8/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param: A: An integer array
    @param: B: An integer array
    @return: a double whose format is *.5 or *.0
    """
    def findMedianSortedArrays(self, A, B):
        # write your code here
        n = len(A) + len(B)
        if (n % 2 == 0):
            return (self.findKth(A, 0, B, 0, n // 2) + self.findKth(A, 0, B, 0, n // 2 + 1)) / 2
            
        return self.findKth(A, 0, B, 0, n // 2 + 1)
        
    def findKth(self, A, start_A, B, start_B, k):
        if start_A >= len(A):
            return B[start_B + k - 1]
            
        if start_B >= len(B):
            return A[start_A + k - 1]
            
        if k == 1:
            return min(A[start_A], B[start_B])
            
        A_halfKth = A[start_A+k//2-1] if start_A + k // 2 - 1 < len(A) else None
        B_halfKth = B[start_B+k//2-1] if start_B + k // 2 - 1 < len(B) else None
        
        if not B_halfKth or (A_halfKth and A_halfKth < B_halfKth):
            return self.findKth(A, start_A + k // 2, B, start_B, k - k // 2)
            
        return self.findKth(A, start_A, B, start_B + k // 2, k - k // 2)
