#!/usr/bin/python3

'''
1564. Interval Search
Given a List of intervals, the length of each interval is 1000, such as [500,1500], [2100,3100].Give a number arbitrarily and determine if the number belongs to any of the intervals.return True or False.

Example
Given:

List = [[100,1100],[1000,2000],[5500,6500]]
number = 6000
Return: True


Author: Yuan Li
Date: 10/15/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param intervalList: 
    @param number: 
    @return: return True or False
    """
    def isInterval(self, intervalList, number):
        # Write your code here
        for intv in intervalList:
            if intv[0] <= number <= intv[1]:
                return "True"
                
        return "False"

