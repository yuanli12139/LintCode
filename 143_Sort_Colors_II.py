#!/usr/bin/python3

'''
143. Sort Colors II
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Example
Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].

Challenge
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory. Can you do it without using extra memory?


Author: Yuan Li
Date: 6/17/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param colors: A list of integer
    @param k: An integer
    @return: nothing
    """
    def sortColors2(self, colors, k):
        # write your code here
        if colors == None or len(colors) == 0:
            return
        
        self.rainbowSort(colors, 0, len(colors) - 1, 1, k)
        
    def rainbowSort(self, colors, start, end, color_start, color_end):
        if color_start == color_end or start == end:
            return
        
        color_mid = (color_start + color_end) // 2
        l, r = start, end
        while l <= r:
            while l <= r and colors[l] <= color_mid:
                l += 1
                
            while l <= r and colors[r] > color_mid:
                r -= 1
                
            if l <= r:
                colors[l], colors[r] = colors[r], colors[l]
                l += 1
                r -= 1
                
        self.rainbowSort(colors, start, r, color_start, color_mid)
        self.rainbowSort(colors, l, end, color_mid + 1, color_end)
        