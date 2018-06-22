#!/usr/bin/python3

'''
137. Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

How we serialize an undirected graph:

Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

   1
  / \
 /   \
0 --- 2
     / \
     \_/
     
Example
return a deep copied graph.


Author: Yuan Li
Date: 6/21/2018 
Difficulty: Medium
'''

"""
Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
"""

class Solution:
    """
    @param: node: A undirected graph node
    @return: A undirected graph node
    """
    def cloneGraph(self, node):
        # write your code here
        if node == None:
            return node
                
        queue = [node]
        nodes = set([node])
        while queue:
            curr_node = queue.pop()
            
            for n in curr_node.neighbors:
                if n not in nodes:
                    queue.append(n)
                    nodes.add(n)
        
        nodes_copied = {}     
        for n in nodes:
            nodes_copied[n] = UndirectedGraphNode(n.label)
            
        for n in nodes_copied:
            for nb in n.neighbors:
                nodes_copied[n].neighbors.append(nodes_copied[nb])
            
        return nodes_copied[node]
        