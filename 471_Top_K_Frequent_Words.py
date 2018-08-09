#!/usr/bin/python3

'''
471. Top K Frequent Words
Given a list of words and an integer k, return the top k frequent words in the list.

Example
Given

[
    "yes", "lint", "code",
    "yes", "code", "baby",
    "you", "baby", "chrome",
    "safari", "lint", "code",
    "body", "lint", "code"
]
for k = 3, return ["code", "lint", "baby"].

for k = 4, return ["code", "lint", "baby", "yes"],

Challenge
Do it in O(nlogk) time and O(n) extra space.

Notice
You should order the words by the frequency of them in the return list, the most frequent one comes first. If two words has the same frequency, the one with lower alphabetical order come first.


Author: Yuan Li
Date: 8/8/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param words: an array of string
    @param k: An integer
    @return: an array of string
    """
    def topKFrequentWords(self, words, k):
        # write your code here
        import heapq
        
        class WordCount:
            def __init__(self, word, count):
                self.word = word
                self.count = count
                
            def __lt__(self, other):
                if self.count != other.count:
                    return self.count < other.count
                    
                return self.word > other.word
        
        word_cnt = collections.Counter(words)
        
        mostK = []
        for word, cnt in word_cnt.items():
            heapq.heappush(mostK, WordCount(word, cnt))
            
            if len(mostK) > k:
                heapq.heappop(mostK)
                
        return [heapq.heappop(mostK).word for _ in range(k)][::-1]
