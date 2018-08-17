#!/usr/bin/python3

'''
63. Search in Rotated Sorted Array II
Follow up for 62. Search in Rotated Sorted Array:

What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Example
Given [1, 1, 0, 1, 1, 1] and target = 0, return true.
Given [1, 1, 1, 1, 1, 1] and target = 0, return false.


Author: Yuan Li
Date: 8/16/2018 
Difficulty: Medium
'''

# worst case: [1, 1, 1, 1, ..., 1] - O(n)
class Solution:
    """
    @param A: an integer ratated sorted array and duplicates are allowed
    @param target: An integer
    @return: a boolean 
    """
    def search(self, A, target):
        # write your code here
        if not A:
            return False
            
        start, end = 0, len(A) - 1
        while start + 1 < end:
            mid = (start + end) // 2
            if A[mid] == target:
                return True
            
            if A[start] == A[mid]:
                start += 1
                continue
            
            if A[end] == A[mid]:
                end = mid
                continue
            
            if A[start] < A[mid]:
                if A[start] <= target <= A[mid]:
                    end = mid
                else:
                    start = mid
            else:
                if A[mid] <= target <= A[-1]:
                    start = mid
                else:
                    end = mid
                    
        if A[start] == target or A[end] == target:
            return True
            
        return False
