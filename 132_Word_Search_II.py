#!/usr/bin/python3

'''
132. Word Search II
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. A word can start from any position in the matrix and go left/right/up/down to the adjacent position. One character only be used once in one word. No same word in dictionary

Example
Given matrix:
d o a f
a g a i
d c a n

and dictionary:
{"dog", "dad", "dgdg", "can", "again"}

return {"dog", "dad", "can", "again"}

dog:
[d][o] a  f
 a [g] a  i
 d  c  a  n

dad:
[d] o  a  f
[a] g  a  i
[d] c  a  n

can:
 d  o  a  f
 a  g  a  i
 d [c][a][n]

again:
 d  o  a  f
[a][g][a][i]
 d  c  a [n]

Challenge
Using trie to implement your algorithm.


Author: Yuan Li
Date: 1/7/2019 
Difficulty: Hard
'''

class TrieNode:
    def __init__(self):
        self.children = {}
        # self.is_word = False
        self.word = None
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        
        # node.is_word = True
        node.word = word
        
    # def find(self, prefix):
    #     node = self.root
    #     for ch in prefix:
    #         if ch not in node.children:
    #             return None
    #         node = node.children[ch]
        
    #     return node

class Solution:
    """
    @param board: A list of lists of character
    @param words: A list of string
    @return: A list of string
    """
    def __init__(self):
        self.trie = Trie()
        self.directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    def wordSearchII(self, board, words):
        # write your code here
        if not board or not board[0] or not words:
            return []
            
        # build trie
        for word in words:
            self.trie.insert(word)
            
        # search words    
        res = set()
        for r in range(len(board)):
            for c in range(len(board[0])):
                node = self.trie.root.children.get(board[r][c])
                self.dfs(board, r, c, node, set([(r, c)]), res)
        
        return list(res)
        
    def dfs(self, board, r, c, node, visited, res):
        if node is None:
            return
        
        # could be a word or prefix
        if node.word:
            res.add(node.word)
        
        for dr, dc in self.directions:
            nr = r + dr
            nc = c + dc
            
            if not self.valid(board, nr, nc, visited):
                continue
            
            visited.add((nr, nc))
            self.dfs(board, nr, nc, node.children.get(board[nr][nc]), visited, res)
            visited.remove((nr, nc))
            
    def valid(self, board, r, c, visited):
        return 0 <= r < len(board) and 0 <= c < len(board[0]) and (r, c) not in visited

