#!/usr/bin/python3

'''
183. Wood Cut
Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

Example
For L=[232, 124, 456], k=7, return 114.

Challenge
O(n log Len), where Len is the longest length of the wood.

Notice
You couldn't cut wood into float length.

If you couldn't get >= k pieces, return 0.


Author: Yuan Li
Date: 11/24/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param L: Given n pieces of wood with length L[i]
    @param k: An integer
    @return: The maximum length of the small pieces
    """
    def woodCut(self, L, k):
        # write your code here
        if not L:
            return 0
        
        # O(log(max(L)))    
        start, end = 1, max(L)
        while start + 1 < end:
            mid = (start + end) // 2
            if self.getNumPieces(L, mid) >= k:
                start = mid
            else:
                end = mid
                
        if self.getNumPieces(L, end) >= k:
            return end
        if self.getNumPieces(L, start) >= k:
            return start
        return 0
                
    # O(n)            
    def getNumPieces(self, L, length):
        return sum(l // length for l in L)

