#!/usr/bin/python3

'''
802. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the number 0.

You may assume that there will be only one unique solution.

Example
Given a Sudoku puzzle:
https://lintcode-media.s3.amazonaws.com/problem/250px-Sudoku-by-L2G-20050714.svg.png

Return its solution:
https://lintcode-media.s3.amazonaws.com/problem/250px-Sudoku-by-L2G-20050714_solution.svg.png


Author: Yuan Li
Date: 8/6/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param board: the sudoku puzzle
    @return: nothing
    """
    def solveSudoku(self, board):
        # write your code here
        rowSet = [set() for i in range(9)]
        colSet = [set() for i in range(9)]
        blkSet = [set() for i in range(9)]

        toFill = []
        for r in range(9):
            for c in range(9):
                if board[r][c] == 0:
                    toFill.append([r, c])
                    continue
                    
                rowSet[r].add(board[r][c])
                colSet[c].add(board[r][c])
                blkSet[r//3*3+c//3].add(board[r][c])

        self.dfs(board, toFill, 0, rowSet, colSet, blkSet)
                
    def dfs(self, board, toFill, startIdx, rowSet, colSet, blkSet):
        if startIdx == len(toFill):
            return True
            
        r, c = toFill[startIdx]
        
        for num in range(1, 10):
            if (num not in rowSet[r]) and (num not in colSet[c]) and (num not in blkSet[r//3*3+c//3]):
                board[r][c] = num
                rowSet[r].add(num)
                colSet[c].add(num)
                blkSet[r//3*3+c//3].add(num)
                
                isSolved = self.dfs(board, toFill, startIdx + 1, rowSet, colSet, blkSet)
                
                if isSolved:
                    return True
                
                board[r][c] = 0
                rowSet[r].remove(num)
                colSet[c].remove(num)
                blkSet[r//3*3+c//3].remove(num)
                
        return False
