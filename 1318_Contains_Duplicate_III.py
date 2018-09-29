#!/usr/bin/python3

'''
1318. Contains Duplicate III
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example
Given nums = [1,3,1], k = 1, t = 1, return false.


Author: Yuan Li
Date: 9/29/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param nums: the given array
    @param k: the given k
    @param t: the given t
    @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
    """
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        # Write your code here
        if k < 1 or t < 0:
            return False
        
        buckets = {}
        for i, n in enumerate(nums):
            # index difference <= k
            if i > k:
                del buckets[nums[i-k-1] // (t + 1)]
            
            bucket = n // (t + 1)
            
            if bucket in buckets:
                return True
            if bucket + 1 in buckets and abs(n - buckets[bucket+1]) <= t:
                return True
            if bucket - 1 in buckets and abs(n - buckets[bucket-1]) <= t:
                return True
                
            # new bucket
            buckets[bucket] = n
                
        return False
        
