#!/usr/bin/python3

'''
62. Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Example
For [4, 5, 1, 2, 3] and target=1, return 2.

For [4, 5, 1, 2, 3] and target=0, return -1.

Challenge
O(logN) time


Author: Yuan Li
Date: 5/20/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param A: an integer rotated sorted array
    @param target: an integer to be searched
    @return: an integer
    """
    def search(self, A, target):
        # write your code here
        if not A:
            return -1
            
        start, end = 0, len(A) - 1
        while start + 1 < end:
            mid = int((start + end) / 2)
            if A[mid] == target:
                return mid
            
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
                    
        if A[start] == target:
            return start
        if A[end] == target:
            return end
        return -1
      