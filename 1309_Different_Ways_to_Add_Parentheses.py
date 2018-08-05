#!/usr/bin/python3

'''
1309. Different Ways to Add Parentheses
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2

Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

Reference
https://zxi.mytechroad.com/blog/leetcode/leetcode-241-different-ways-to-add-parentheses/


Author: Yuan Li
Date: 8/4/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param input: a string
    @return: return List[int]
    """
    def __init__(self):
        self.memo = {}
    
    def diffWaysToCompute(self, input):
        # write your code here
        if not input:
            return []

        return self.dfs(input)
        
    def dfs(self, input):
        if (input in self.memo):
            return self.memo[input]
        
        # if self.countOperator(input) == 0:
        #     self.memo[input] = [int(input)]
        #     return [int(input)]
        
        res = []
        for i in range(1, len(input) - 1):
            if input[i].isdigit():
                continue
            
            left, right = input[:i], input[i+1:]
            for l in self.dfs(left):
                for r in self.dfs(right):
                    res.append(self.compute(l, input[i], r))
        
        # no operator, single number
        if not res:
            res.append(int(input))
        
        self.memo[input] = res
            
        return res
            
    # def countOperator(self, s):
    #     count = 0
    #     for c in s:
    #         count += c in ['+', '-', '*'] 
    
    #     return count
        
    def compute(self, a, op, b):
        # eq = str(a) + op + str(b)
        # return eval(eq)
        if op == '+':
            return a + b
            
        if op == '-':
            return a - b
            
        return a * b
        