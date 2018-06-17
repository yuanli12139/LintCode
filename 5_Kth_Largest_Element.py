#!/usr/bin/python3

'''
5. Kth Largest Element
Find K-th largest element in an array.

Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Challenge
O(n) time, O(1) extra memory.


Author: Yuan Li
Date: 6/16/2018 
Difficulty: Medium
'''

class Solution:
    # @param k & A a integer and an array
    # @return ans a integer
    def kthLargestElement(self, k, A):
        if A == None or len(A) == 0:
            return
        
        start, end = 0, len(A) - 1
        return self.quickSelect(start, end, k, A)
        
    def quickSelect(self, start, end, k, A):
        if start == end:
            return A[start]
            
        left, right = start, end
        pivot = A[(left + right) // 2]
        while left <= right:
            while left <= right and A[left] > pivot:
                left += 1
                
            while left <= right and A[right] < pivot:
                right -= 1
                
            if left <= right:
                A[left], A[right] = A[right], A[left]
                left += 1
                right -= 1
                
        if start + k - 1 <= right:
            return self.quickSelect(start, right, k, A)
            
        if start + k - 1 >= left:
            return self.quickSelect(left, end, k - (left - start), A)
            
        return A[right + 1]
        