#!/usr/bin/python3

'''
442. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example
insert("lintcode")
search("code")
>>> false
startsWith("lint")
>>> true
startsWith("linterror")
>>> false
insert("linterror")
search("lintcode)
>>> true
startsWith("linterror")
>>> true

Notice
You may assume that all inputs are consist of lowercase letters a-z.

Reference
https://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/


Author: Yuan Li
Date: 9/1/2018 
Difficulty: Medium
'''

# time: O(l)
# space: O(prefixes) = O(n * l^2)
class Trie:
    
    def __init__(self):
        # do intialization if necessary
        self.root = {}

    """
    @param: word: a word
    @return: nothing
    """
    def insert(self, word):
        # write your code here
        p = self.root
        for c in word:
            if c not in p:
                p[c] = {}
            
            p = p[c]
            
        p['#'] = True

    """
    @param: word: A string
    @return: if the word is in the trie.
    """
    def search(self, word):
        # write your code here
        node = self.find(word)
        return node is not None and '#' in node 

    """
    @param: prefix: A string
    @return: if there is any word in the trie that starts with the given prefix.
    """
    def startsWith(self, prefix):
        # write your code here
        return self.find(prefix) is not None
        
    def find(self, prefix):
        p = self.root
        for c in prefix:
            if c not in p:
                return None
                
            p = p[c]
            
        return p
