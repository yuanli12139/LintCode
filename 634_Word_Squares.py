#!/usr/bin/python3

'''
634. Word Squares
Given a set of words without duplicates, find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y

Example
Given a set ["area","lead","wall","lady","ball"]
return [["wall","area","lead","lady"],["ball","area","lead","lady"]]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

Given a set ["abat","baba","atan","atal"]
return [["baba","abat","baba","atan"],["baba","abat","baba","atal"]]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

Notice
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.


Author: Yuan Li
Date: 1/6/2019 
Difficulty: Hard
'''

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False
        self.words = []

class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            
            node = node.children[ch]
            node.words.append(word)
            
        node.is_word = True
        
    def find(self, prefix):
        node = self.root
        for ch in prefix:
            if ch not in node.children:
                return None
                
            node = node.children[ch]
            
        return node
        
    def startWith(self, prefix):
        node = self.find(prefix)
        return [] if node is None else node.words

class Solution:
    """
    @param: words: a set of words without duplicates
    @return: all word squares
    """
    def __init__(self):
        self.trie = Trie()
    
    def wordSquares(self, words):
        # write your code here
        for word in words:
            self.trie.insert(word)
            
        res = []
        for word in words:
            self.dfs([word], res)
            
        return res
        
    def dfs(self, square, res):
        start = len(square)
        n = len(square[0])
        if start == n:
            res.append(square[:])
            return
        
        # pruning
        for r in range(start, n):
            prefix = "".join([square[c][r] for c in range(start)])
            if self.trie.find(prefix) is None:
                return
        
        prefix = "".join([square[c][start] for c in range(start)])
        for word in self.trie.startWith(prefix):
            square.append(word)
            self.dfs(square, res)
            square.pop()

