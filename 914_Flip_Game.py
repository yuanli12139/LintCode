#!/usr/bin/python3

'''
914. Flip Game

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

Example
Example1

Input:  s = "++++"
Output: 
[
  "--++",
  "+--+",
  "++--"
]

Example2

Input: s = "---+++-+++-+"
Output: 
[
	"---+++-+---+",
	"---+++---+-+",
	"---+---+++-+",
	"-----+-+++-+"
]

Author: Yuan Li
Date: 2/17/2019 
Difficulty: Easy
'''

class Solution:
    """
    @param s: the given string
    @return: all the possible states of the string after one valid move
    """
    def generatePossibleNextMoves(self, s):
        # write your code here
        res = []
        for i in range(len(s) - 1):
            if s[i:i+2] == "++":
                res.append(s[:i] + "--" + s[i+2:])
    
        return res

