#!/usr/bin/python3

'''
59. 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

Example
For example, given array S = [-1 2 1 -4], and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Challenge
O(n^2) time, O(1) extra space


Author: Yuan Li
Date: 6/16/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @param target: An integer
    @return: return the sum of the three integers, the sum closest target.
    """
    def threeSumClosest(self, numbers, target):
        # write your code here
        if numbers == None or len(numbers) < 3:
            return
        
        numbers.sort()
        
        res = numbers[0] + numbers[1] + numbers[2]
        diff = abs(numbers[0] + numbers[1] + numbers[2] - target)
        for i in range(0, len(numbers) - 2):
            left, right = i + 1, len(numbers) - 1
            while left < right:
                if abs(target - res) > abs(target - numbers[i] - numbers[left] - numbers[right]):
                    res = numbers[i] + numbers[left] + numbers[right]
                
                if numbers[left] + numbers[right] < target - numbers[i]:
                    diff = min(diff, target - numbers[i] - numbers[left] - numbers[right])
                    left += 1
                    
                else:
                    diff = min(diff, numbers[i] + numbers[left] + numbers[right] - target)
                    right -= 1
                 
        return res
        