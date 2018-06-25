#!/usr/bin/python3

'''
605. Sequence Reconstruction
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10^4. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example
Given org = [1,2,3], seqs = [[1,2],[1,3]]
Return false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Given org = [1,2,3], seqs = [[1,2]]
Return false
Explanation:
The reconstructed sequence can only be [1,2].

Given org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Return true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].

Given org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Return true


Author: Yuan Li
Date: 6/24/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param org: a permutation of the integers from 1 to n
    @param seqs: a list of sequences
    @return: true if it can be reconstructed only one or false
    """
    def sequenceReconstruction(self, org, seqs):
        # write your code here
        # 1. create graph
        # 1.1 create nodes
        graph = {}
        for seq in seqs:
            for n in seq:
                graph[n] = set()
        
        # 1.2 create edges
        for seq in seqs:
            if len(seq) > 0 and (seq[0] < 1 or seq[0] > len(org)):
                return False
                
            for i in range(len(seq) - 1):
                if seq[i] < 1 or seq[i] > len(org):
                    return False
                        
                graph[seq[i]].add(seq[i+1])

        # 2. calculate in-degrees
        inDegrees = {}
        for node in graph:
            inDegrees[node] = 0
            
        for node in graph:
            for edge in graph[node]:
                inDegrees[edge] += 1
        
        # 3. enqueue of in-degree == 0
        queue = []
        for i in inDegrees:
            if inDegrees[i] == 0:
                queue.append(i)
        
        # 4. in-degree-- & enqueue new in-degree == 0
        count = 0
        while len(queue) == 1:
            curr_node = queue.pop(0)
            
            if count > len(org) - 1:
                return False
            
            if curr_node != org[count]:
                return False
            count += 1
            
            for next_node in graph[curr_node]:
                inDegrees[next_node] -= 1
                if inDegrees[next_node] == 0:
                    queue.append(next_node)
                    
        if len(queue) > 1:
            return False
        return count == len(org)
        