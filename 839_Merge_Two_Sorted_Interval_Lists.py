#!/usr/bin/python3

'''
839. Merge Two Sorted Interval Lists
Merge two sorted (ascending) lists of interval and return it as a new sorted list. The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.

Example
Given list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)], return [(1,4),(5,6)].

Notice
The intervals in the given list do not overlap.
The intervals in different lists may overlap.


Author: Yuan Li
Date: 8/13/2018 
Difficulty: Easy
'''

"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

# O(n + m)
class Solution:
    """
    @param list1: one of the given list
    @param list2: another list
    @return: the new sorted list of interval
    """
    def __init__(self):
        self.res = []
    
    def mergeTwoInterval(self, list1, list2):
        # write your code here
        if not list1:
            return list2
            
        if not list2:
            return list1
            
        i, j = 0, 0
        while i < len(list1) and j < len(list2):
            if list1[i].start < list2[j].start:
                buf = list1[i]
                i += 1 
            else:
                buf = list2[j]
                j += 1
                
            self.merge(buf)
            
        while i < len(list1):
            self.merge(list1[i])
            i += 1
            
        while j < len(list2):
            self.merge(list2[j])
            j += 1

        return self.res
        
    def merge(self, intv):
        if not self.res or self.res[-1].end < intv.start:
            self.res.append(intv)
        else:
            self.res[-1].end = max(self.res[-1].end, intv.end)
