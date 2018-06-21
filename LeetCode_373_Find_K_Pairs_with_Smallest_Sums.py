#!/usr/bin/python3

'''
373. Find K Pairs with Smallest Sums (LeetCode)
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]


Author: Yuan Li
Date: 6/20/2018 
Difficulty: Medium
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

from heapq import *

class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        res = []
        if not nums1 or not nums2:
            return res
        
        pq = []
        for i1 in range(len(nums1)):
            heappush(pq, [nums1[i1] + nums2[0], i1, 0])
            
        while pq and len(res) < k:
            curr_pair = heappop(pq)
            res.append([nums1[curr_pair[1]], nums2[curr_pair[2]]])
            
            if curr_pair[2] + 1 < len(nums2):
                heappush(pq, [nums1[curr_pair[1]] + nums2[curr_pair[2] + 1], curr_pair[1], curr_pair[2] + 1])
                
        return res
                