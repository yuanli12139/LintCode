#!/usr/bin/python3

'''
360. Sliding Window Median
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, find the median of the element inside the window at each moving. (If there are even numbers in the array, return the N/2-th number after sorting the element in the window. )

Example
For array [1,2,7,8,5], moving window size k = 3. return [2,7,7]

At first the window is at the start of the array like this

[ | 1,2,7 | ,8,5] , return the median 2;

then the window move one step forward.

[1, | 2,7,8 | ,5], return the median 7;

then the window move one step forward again.

[1,2, | 7,8,5 | ], return the median 7;

Challenge
O(nlog(n)) time

Reference
https://zxi.mytechroad.com/blog/difficulty/hard/leetcode-480-sliding-window-median/


Author: Yuan Li
Date: 11/14/2018 
Difficulty: Hard
'''

# O(max(klog(k) + (n-k+1)*k))
from bisect import bisect_left, insort_left 

class Solution:
    """
    @param nums: A list of integers
    @param k: An integer
    @return: The median of the element inside the window at each moving
    """
    def medianSlidingWindow(self, nums, k):
        # write your code here
        medians = []
        if k == 0:
            return medians
            
        win = sorted(nums[:k-1]) # first k-1 nums
        
        for i in range(k - 1, len(nums)):
            insort_left(win, nums[i]) # insert in sorted order
            medians.append(win[(k-1)//2])
            win.pop(bisect_left(win, nums[i-k+1])) # erase
            
        return medians

