#!/usr/bin/python3

'''
347. Top K Frequent Elements (LeetCode)
Given a non-empty array of integers, return the k most frequent elements. 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


Author: Yuan Li
Date: 9/10/2018 
Difficulty: Medium
'''

class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        return [item[0] for item in collections.Counter(nums).most_common(k)]

