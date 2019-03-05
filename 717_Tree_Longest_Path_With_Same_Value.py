#!/usr/bin/python3

'''
717. Tree Longest Path With Same Value

We consider an undirected tree with N nodes, numbered from 1 to N, Additionally, each node also has a label attached to it and the label is an integer value. Note that different nodes can have identical labels. You need to write a function , that , given a zero-indexed array A of length N, where A[J] is the label value of the (J + 1)-th node in the tree, and a zero-indexed array E of length K = (N - 1) * 2 in which the edges of the tree are described (for every 0 <= j <= N -2 values E[2 * J] and E[2 * J + 1] represents and edge connecting node E[2 * J] with node E[2 * J + 1])， returns the length of the longest path such that all the nodes on that path have the same label. Then length of a path if defined as the number of edges in that path.

Example
Example1

Input: A = [1, 1, 1 ,2, 2] and E = [1, 2, 1, 3, 2, 4, 2, 5]
Output: 2
Explanation: 
described tree appears as follows:
​```
                   1 （value = 1）
                 /   \
    (value = 1) 2     3 (value = 1)
               /  \
 (value = 2)  4     5 (value = 2)
​```
The longest path (in which all nodes have the save value of 1) is (2 -> 1 -> 3). The number of edges on this path is 2, thus, that is the answer.

Example2

Input: A = [1, 2, 1 ,2, 2] and E = [1, 2, 1, 3, 2, 4, 2, 5]
Output: 2
Explanation: 
described tree appears as follows:
​```
                   1 （value = 1）
                 /   \
    (value = 2) 2     3 (value = 1)
               /  \
 (value = 2)  4     5 (value = 2)
​```
The longest path (in which all nodes have the save value of 2) is (4 -> 2 -> 5). The number of edges on this path is 2, thus, that is the answer.

Notice
Assume that: 1 <= N <= 1000


Author: Yuan Li
Date: 3/3/2019 
Difficulty: Medium
'''

class Solution:
    """
    @param A: as indicated in the description
    @param E: as indicated in the description
    @return: Return the number of edges on the longest path with same value.
    """
    def LongestPathWithSameValue(self, A, E):
        # write your code here
        edges = {}
        for i in range(0, len(E), 2):
            edges.setdefault(E[i], set([E[i+1]])).add(E[i+1])
            edges.setdefault(E[i+1], set([E[i]])).add(E[i])
        
        longest = 0
        for j in range(1, len(A) + 1):
            longest = max(longest, self.dfs(A, edges, j, set([j]), 0))
          
        return longest

    def dfs(self, A, edges, j, visited, length):
        l = length
        for adj in edges[j]:
            if adj in visited or A[adj-1] != A[j-1]:
                continue
            
            visited.add(adj)
            l = max(l, self.dfs(A, edges, adj, visited, length + 1))
            visited.remove(adj)
            
        return l
