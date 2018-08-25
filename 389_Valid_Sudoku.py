#!/usr/bin/python3

'''
389. Valid Sudoku
Determine whether a Sudoku is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example
The following partially filed sudoku is valid.
https://lintcode-media.s3.amazonaws.com/problem/valid-sudoku.png

Clarification
What is Sudoku?

http://sudoku.com.au/TheRules.aspx
https://zh.wikipedia.org/wiki/數獨
https://en.wikipedia.org/wiki/Sudoku
http://baike.baidu.com/subview/961/10842669.htm

Notice
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.


Author: Yuan Li
Date: 8/24/2018 
Difficulty: Easy
'''

class Solution:
    """
    @param board: the board
    @return: whether the Sudoku is valid
    """
    def isValidSudoku(self, board):
        # write your code here
        rowSet = [set() for r in range(9)]
        colSet = [set() for c in range(9)]
        blkSet = [set() for b in range(9)]
        
        for r in range(9):
            for c in range(9):
                num = board[r][c]
                if num == '.':
                    continue
                
                b = r // 3 * 3 + c // 3
                if (num in rowSet[r]) or (num in colSet[c]) or (num in blkSet[b]):
                    return False
                    
                rowSet[r].add(num)
                colSet[c].add(num)
                blkSet[b].add(num)
                
        return True
