/*
33. N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example
There exist two distinct solutions to the 4-queens puzzle:

[
  // Solution 1
  [".Q..",
   "...Q",
   "Q...",
   "..Q."
  ],
  // Solution 2
  ["..Q.",
   "Q...",
   "...Q",
   ".Q.."
  ]
]

Challenge
Can you do it without recursion?


Author: Yuan Li
Date: 7/19/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        vector<vector<string>> res;
        vector<int> cols;
        
        dfs(n, cols, res);
        return res;
    }
    
    void dfs(int n, vector<int> cols, vector<vector<string>> &res) {
        if (n <= 0) {
            return;
        }
        
        if (cols.size() == n) {
            res.push_back(drawChessboard(cols));
            return;
        }
        
        for (int c = 0; c < n; ++c) {
            if (!isValid(cols, c)) {
                continue;
            }
            
            cols.push_back(c);
            dfs(n, cols, res);
            cols.pop_back();
        }
    }
    
    vector<string> drawChessboard(vector<int> &cols) {
        vector<string> queens;
        for (int r = 0; r < cols.size(); ++r) {
            string queen;
            for (int c = 0; c < cols.size(); ++c) {
                if (c == cols[r]){
                    queen += 'Q';
                } else {
                    queen += '.';
                }
            }
            queens.push_back(queen);
        }
        
        return queens;
    }
    
    bool isValid(vector<int> &cols, int new_c) {
        int new_r = cols.size();
        for (int r = 0; r < cols.size(); ++r) {
            // duplicates
            if (cols[r] == new_c) {
                return false;
            }
            // diagonal attack
            if (r - cols[r] == new_r - new_c) {
                return false;
            }
            // back-diagonal attack
            if (r + cols[r] == new_r + new_c) {
                return false;
            }
        }
        
        return true;
    }
};
