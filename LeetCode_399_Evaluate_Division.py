#!/usr/bin/python3

'''
399. Evaluate Division (LeetCode)
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.


Author: Yuan Li
Date: 8/16/2018 
Difficulty: Medium
'''

# DFS - O(eq)
class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        ans = []
        
        # create graph
        graph = {}
        for (x, y), val in zip(equations, values):
            graph.setdefault(x, {})[y] = val
            graph.setdefault(y, {})[x] = 1 / val
        
        # answer queries
        for query in queries:
            x, y = query
            if x not in graph or y not in graph:
                ans.append(-1.0)
                continue
            
            ans.append(self.dfs(x, y, graph, set()))

        return ans

    # return a / c
    def dfs(self, a, c, graph, visited):
        if a == c:
            return 1.0
        
        visited.add(a)
        for b, val in graph[a].items():
            if b in visited:
                continue
                
            visited.add(b)
            res = self.dfs(b, c, graph, visited) 

            if res > 0:
                return graph[a][b] * res # a / c = a / b * b / c
                
        return -1.0
