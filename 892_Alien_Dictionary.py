#!/usr/bin/python3

'''
892. Alien Dictionary
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return the smallest in lexicographical order

Example
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf"

Given the following words in dictionary,

[
  "z",
  "x"
]
The correct order is: "zx".


Author: Yuan Li
Date: 6/24/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param words: a list of words
    @return: a string which is correct order
    """
    def alienOrder(self, words):
        # Write your code here
        # 1. create graph
        # 1.1 create nodes
        graph = {}
        for w in words:
            for c in w:
                graph[c] = set([])
        
        # 1.2 create edges
        for i in range(len(words) - 1):
            ci = 0
            while ci < len(words[i]) and ci < len(words[i+1]):
                if words[i][ci] != words[i+1][ci]:
                    graph[words[i][ci]].add(words[i+1][ci])
                    break
                ci += 1
        
        # 2. calculate in-degrees
        inDegrees = {}
        for c in graph:
            inDegrees[c] = 0
        
        for c in graph:
            for nc in graph[c]:
                inDegrees[nc] += 1
    
        # 3. add nodes with in-degree == 0 into queue
        queue = []
        for i in inDegrees:
            if inDegrees[i] == 0:
                queue.append(i)

        # 4. decrease in-degrees and add new node with 0 in-degree
        order = ""
        count = 0
        while queue:
            queue.sort() # lexicographical order (priority queue/heapq works, too)
            curr_ch = queue.pop(0)
            order += curr_ch
            count += 1
            
            for nc in graph[curr_ch]:
                inDegrees[nc] -= 1
                if inDegrees[nc] == 0:
                    queue.append(nc)
        
        if count == len(graph):            
            return order
        return ""
            