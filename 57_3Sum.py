#!/usr/bin/python3

'''
57. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:

(-1, 0, 1)
(-1, -1, 2)


Author: Yuan Li
Date: 6/14/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @return: Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        # write your code here
        res = []
        
        if numbers == None or len(numbers) < 3:
            return []
            
        numbers.sort()
        
        for i in range(0, len(numbers) - 2):
            if i and numbers[i] == numbers[i-1]:
                continue
            
            target = -numbers[i]
            left, right = i + 1, len(numbers) - 1
            while left < right:
                if numbers[left] + numbers[right] == target:
                    res.append([-target, numbers[left], numbers[right]])
                    left += 1
                    right -= 1
                    
                    while left < right and numbers[left] == numbers[left - 1]:
                        left += 1
                    while left > right and numbers[right] == numbers[right + 1]:
                        right -= 1
                        
                elif numbers[left] + numbers[right] > target:
                    right -= 1
                else:
                    left += 1
                    
        return res
        