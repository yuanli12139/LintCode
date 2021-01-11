/*
1189. Minesweeper
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.

Example
Example 1:

Input: board = ["EEEEE","EEMEE","EEEEE","EEEEE"], Click : [3,0]
Output: ["B1E1B","B1M1B","B111B","BBBBB"]
Example 2:

Input: board = ["B1E1B","B1M1B", "B111B","BBBBB"], Click : [1,2]
Output: ["B1E1B","B1X1B","B111B","BBBBB"]

Notice
1.The range of the input matrix's height and width is [1,50].
2.The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
3.The input board won't be a stage when game is over (some mines have been revealed).
4.For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.


Author: Yuan Li
Date: 1/10/2021
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param board: a board
     * @param click: the position
     * @return: the new board
     */
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // Write your code here
        vector<vector<char>> res = board;
        
        if (board.empty() || board[0].empty()) {
            return res;
        }
        
        visited_.resize(board.size(), vector<bool>(board[0].size(), false));
        
        q_.push(click);
        visited_[click[0]][click[1]] = true;
        
        while (!q_.empty()) {
            int r = q_.front()[0], c = q_.front()[1];
            int nc, nr;
            
            q_.pop();
            if (board[r][c] == 'M') {
                res[r][c] = 'X';
                break;
            }

            int adj_mine = 0;
            for (int n = 0; n < 8; ++n) {
                nr = r + dr_[n];
                nc = c + dc_[n];
                if (isValid_(board, nr, nc) && board[nr][nc] == 'M') {
                    adj_mine++;
                }
            }
            
            if (adj_mine) {
                res[r][c] = adj_mine + '0';
                continue;
            }
             
            res[r][c] = 'B';
            for (int n = 0; n < 8; ++n) {
                nr = r + dr_[n];
                nc = c + dc_[n];
                if (isValid_(board, nr, nc)) {
                    q_.push({nr, nc});
                    visited_[nr][nc] = true;
                }
            }
        }
        
        return res;
    }
    
private:
    vector<int> dr_ = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dc_ = {0, 0, -1, 1, -1, 1, -1, 1};
    queue<vector<int>> q_;
    vector<vector<bool>> visited_;
    
private:
    bool isValid_(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visited_[r][c]) {
            return false;
        }
        return true;
    }
};
