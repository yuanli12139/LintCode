#!/usr/bin/python3

'''
464. Sort Integers II
Given an integer array, sort it in ascending order. Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.

Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].


Author: Yuan Li
Date: 6/19/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param A: an integer array
    @return: nothing
    """
    def sortIntegers2(self, A):
        # write your code here
        if A == None or len(A) <= 1:
            return
        
        # run quick sort
        # self.quickSort(A, 0, len(A) - 1)
        
        # run merge sort
        temp = [None] * len(A)
        self.mergeSort(A, 0, len(A) - 1, temp)
        
    def quickSort(self, A, start, end):
        if start >= end:
            return
        
        left, right = start, end
        pivot = A[(start + end) // 2]
        while left <= right:
            while left <= right and A[left] < pivot:
                left += 1
            
            while left <= right and A[right] > pivot:
                right -= 1
                
            if left <= right:
                A[left], A[right] = A[right], A[left]
                left += 1
                right -= 1
                
        self.quickSort(A, start, right)
        self.quickSort(A, left, end)
        
    def mergeSort(self, A, start, end, temp):
        if start >= end:
            return
        
        mid = (start + end) // 2
        self.mergeSort(A, start, mid, temp)
        self.mergeSort(A, mid + 1, end, temp)
        self.merge(A, start, end, temp)
        
    def merge(self, A, start, end, temp):
        mid = (start + end) // 2
        left, right = start, mid + 1
        index = start
        while left <= mid and right <= end:
            if A[left] < A[right]:
                temp[index] = A[left]
                left += 1
            
            else:
                temp[index] = A[right]
                right += 1
                
            index += 1
                
        while left <= mid:
            temp[index] = A[left]
            left += 1
            index += 1
            
        while right <= end:
            temp[index] = A[right]
            right += 1
            index += 1
        
        A[start:end+1] = temp[start:end+1].copy()
                