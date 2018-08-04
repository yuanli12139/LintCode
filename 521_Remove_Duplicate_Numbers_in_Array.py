#!/usr/bin/python3

'''
521. Remove Duplicate Numbers in Array
Given an array of integers, remove the duplicate numbers in it.

You should:

Do it in place in the array.
Move the unique numbers to the front of the array.
Return the total number of the unique numbers.
Example
Given nums = [1,3,1,4,4,2], you should:

Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
Return the number of unique integers in nums => 4.
Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.

Challenge
Do it in O(n) time complexity.
Do it in O(nlogn) time without extra space.


Author: Yuan Li
Date: 6/17/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param: nums: an array of integers
    @return: the number of unique integers
    """
    def deduplication(self, nums):
        # write your code here
        if nums == None or len(nums) == 0:  
            return 0
        
        if len(nums) == 1:
            return 1
            
        i, j = 0, 0
        s = set()
        while j < len(nums):
            if nums[i] not in s:
                s.add(nums[i])
                i += 1
                j += 1
                continue
                
            if nums[j] in s:
                j += 1
                continue
            
            nums[i], nums[j] = nums[j], nums[i]
         
        # return len(s)        
        return i
        