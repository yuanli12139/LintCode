#!/usr/bin/python3

'''
460. Find K Closest Elements
Given a target number, a non-negative integer target and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

The value k is a non-negative integer and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 10^4
Absolute value of elements in the array and x will not exceed 10^4

Example
Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].

Challenge
O(logn + k) time complexity.


Author: Yuan Li
Date: 5/19/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param A: an integer array
    @param target: An integer
    @param k: An integer
    @return: an integer array
    """
    def kClosestNumbers(self, A, target, k):
        # write your code here
        result = []
        
        if k > 0:
            closest_id = self.findClosest(A, target)
            result.append(A[closest_id])
            
            left, right = closest_id - 1, closest_id + 1
            for i in range(k - 1):
                if self.isLeftClosest(A, target, left, right):
                    result.append(A[left])
                    left -= 1
                elif right < len(A):
                    result.append(A[right])
                    right += 1
                
        return result
                
    def findClosest(self, A, target):
        start, end = 0, len(A) - 1
        while start + 1 < end:
            mid = int((start + end) / 2)
            if A[mid] <= target:
                start = mid
            else:
                end = mid
                
        if target - A[start] <= A[end] - target:
            return start
        return end
        
    def isLeftClosest(self, A, target, left, right):
        if left < 0:
            return False
        if right > len(A) - 1:
            return True
            
        return target - A[left] <= A[right] - target
        