#!/usr/bin/python3

'''
120. Word Ladder
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.


Author: Yuan Li
Date: 6/21/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param: start: a string
    @param: end: a string
    @param: dict: a set of string
    @return: An integer
    """
    def ladderLength(self, start, end, dict):
        # write your code here
        if not dict:
            return 0
            
        if start == end:
            return 1
        
        dict.add(start)
        dict.add(end)
        
        queue = [start]
        visited = set([start])
        length = 1
        while queue:
            length += 1
            qSize = len(queue)
            for i in range(qSize):
                curr_word = queue.pop(0)
                # print(visited, queue, self.nextWord(curr_word, dict))
                for next_word in self.nextWord(curr_word, dict):
                    if next_word == end:
                        return length
                    
                    if next_word not in visited:
                        queue.append(next_word)
                        visited.add(next_word)
                        
        return 0
            
    def nextWord(self, word, dict):
        next_words = set()
        for c in range(ord('a'), ord('z') + 1):
            change = chr(c)
            for i in range(len(word)):
                if word[i] == change:
                    continue
                
                next_word = self.replace(word, i, change)
                if next_word in dict:
                    next_words.add(next_word)
                    
        return next_words
                
    def replace(self, word, index, char):
        prefix = word[:index]
        suffix = word[index+1:]
        
        return prefix + char + suffix
        