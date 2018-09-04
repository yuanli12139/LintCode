#!/usr/bin/python3

'''
1308. Factor Combinations
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Example
input: 1
output:
[]

input: 37
output:
[]

input: 12
output:
[
[2, 6],
[2, 2, 3],
[3, 4]
]

input: 32
output:
[
[2, 16],
[2, 2, 8],
[2, 2, 2, 4],
[2, 2, 2, 2, 2],
[2, 4, 4],
[4, 8]
]

Notice
You may assume that n is always positive.
Factors should be greater than 1 and less than n.


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param n: a integer
    @return: return a 2D array
    """
    def getFactors(self, n):
        # write your code here
        res = []
        if n <= 1:
            return res;
        
        self.dfs(n, 2, [], res)
        return res
        
    def dfs(self, n, start, factors, res):
        if n == 1 and len(factors) > 1:
            res.append(factors[:])
            return

        for factor in range(start, int(math.sqrt(n)) + 1): # math.ceil(math.sqrt(n)) is wrong
            if (n % factor == 0):
                factors.append(factor)
                self.dfs(n // factor, factor, factors, res)
                factors.pop()
            
        if n >= start:
            factors.append(n)
            self.dfs(1, n, factors, res)
            factors.pop()
