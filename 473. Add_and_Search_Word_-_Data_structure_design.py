#!/usr/bin/python3

'''
473. Add and Search Word - Data structure design
Design a data structure that supports the following two operations: addWord(word) and search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or ..

A . means it can represent any one letter.

Example
addWord("bad")
addWord("dad")
addWord("mad")
search("pad")  // return false
search("bad")  // return true
search(".ad")  // return true
search("b..")  // return true

Notice
You may assume that all words are consist of lowercase letters a-z.


Author: Yuan Li
Date: 1/6/2019 
Difficulty: Medium
'''

class TrieNode:
    
    def __init__(self):
        self.children = {}
        self.is_word = False

class WordDictionary:
    
    def __init__(self):
        self.root = TrieNode()
    
    """
    @param: word: Adds a word into the data structure.
    @return: nothing
    """
    def addWord(self, word):
        # write your code here
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_word = True

    """
    @param: word: A word could contain the dot character '.' to represent any one letter.
    @return: if the word is in the data structure.
    """
    def search(self, word):
        # write your code here
        if word == None:
            return False
            
        return self.dfs(word, self.root, 0) 

    def dfs(self, word, node, start):
        if node == None:
            return False
            
        if start == len(word):
            return node.is_word
            
        ch = word[start]
        if ch != '.':
            return self.dfs(word, node.children.get(ch), start + 1)
            
        for _, child in node.children.items():
            if self.dfs(word, child, start + 1):
                return True
                
        return False

