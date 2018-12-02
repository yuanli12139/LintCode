#!/usr/bin/python3

'''
1148. Longest Harmonious Subsequence
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Notice
The length of the input array will not exceed 20,000.


Author: Yuan Li
Date: 12/1/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param nums: a list of integers
    @return: return a integer
    """
    def findLHS(self, nums):
        # write your code here
        cnts = collections.Counter(nums)
        
        max_len = 0
        for n, c in cnts.items():
            harmo_len = c + max(cnts.get(n-1, 0), cnts.get(n+1, 0))
            if harmo_len == c:
                continue
            
            max_len = max(max_len, harmo_len)
        
        return max_len

