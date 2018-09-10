#!/usr/bin/python3

'''
149. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example
Given array [3,2,3,1,2], return 1.


Author: Yuan Li
Date: 9/9/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        # write your code here
        res = 0
        
        if len(prices) <= 1:
            return res
        
        last_min = prices[0]
        for i in range(1, len(prices)):
            p = prices[i]
            
            res = max(res, p - last_min)
            last_min = min(last_min, p)
            
        return res

