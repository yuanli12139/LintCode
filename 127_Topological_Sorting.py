#!/usr/bin/python3

'''
127. Topological Sorting
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Example
For graph as follow:

picture
https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcThE9AgZZszyhwe0o9qpp3VyizdIj9kWwMY50HiQEysXvkSLsoZ

The topological order can be:

[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...

Challenge
Can you do it in both BFS and DFS?


Author: Yuan Li
Date: 6/24/2018 
Difficulty: Medium
'''

"""
Definition for a Directed graph node
class DirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
"""

class Solution:
    """
    @param: graph: A list of Directed graph node
    @return: Any topological order for the given graph.
    """
    def topSort(self, graph):
        # write your code here
        topSorted = []
        
        # calculate in-degree
        in_degree = {}
        for node in graph:
            for neighbor in node.neighbors:
                if neighbor not in in_degree:
                    in_degree[neighbor] = 1
                else:
                    in_degree[neighbor] += 1
                    
        # put nodes with in-degree = 0 in queue
        queue = []
        for node in graph:
            if node not in in_degree:
                queue.append(node)
                topSorted.append(node)
        
        # decrease in-degree and add new nodes with in-degree = 0
        while queue:
            curr_node = queue.pop(0)
            for neighbor in curr_node.neighbors:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
                    topSorted.append(neighbor)
                    
        return topSorted
        