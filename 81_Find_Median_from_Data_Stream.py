#!/usr/bin/python3

'''
81. Find Median from Data Stream
Numbers keep coming, return the median of numbers at every time a new number added.

Example
For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].

For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].

For numbers coming list: [2, 20, 100], return [2, 2, 20].

Challenge
Total run time in O(nlogn).

Clarification
What's the definition of Median?

Median is the number that in the middle of a sorted array. If there are n numbers in a sorted array A, the median is A[(n - 1) / 2]. For example, if A=[1,2,3], median is 2. If A=[1,19], median is 1.


Author: Yuan Li
Date: 11/13/2018 
Difficulty: Hard
'''

from heapq import heappush, heappop

class Solution:
    """
    @param nums: A list of integers
    @return: the median of numbers
    """
    def __init__(self):
        self.max_heap = []
        self.min_heap = []
    
    def medianII(self, nums):
        # write your code here
        medians = []
        for num in nums:
            self.add(num)
            medians.append(-self.max_heap[0])
            
        return medians
        
    def add(self, value):
        if len(self.max_heap) == len(self.min_heap):
            heappush(self.max_heap, -value)
        else:
            heappush(self.min_heap, value)
            
        if self.min_heap and -self.max_heap[0] > self.min_heap[0]:
            heappush(self.max_heap, -heappop(self.min_heap))
            heappush(self.min_heap, -heappop(self.max_heap))

