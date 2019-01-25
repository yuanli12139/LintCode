/*
477. Surrounded Regions
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O''s into 'X''s in that surrounded region.

Example
X X X X
X O O X
X X O X
X O X X

After capture all regions surrounded by 'X', the board should be:
X X X X
X X X X
X X X X
X O X X


Author: Yuan Li
Date: 1/23/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param board: board a 2D board containing 'X' and 'O'
     * @return: nothing
     */
    void surroundedRegions(vector<vector<char>> &board) {
        // write your code here
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int n = board.size();
        int m = board[0].size();
        
        // fill in water from the 4 edges
        for (int r = 0; r < n; ++r) {
            bfs(board, r, 0);
            bfs(board, r, m - 1);
        }
        
        for (int c = 1; c < m - 1; ++c) {
            bfs(board, 0, c);
            bfs(board, n - 1, c);
        }
        
        for (auto &row : board) {
            for (char &p : row) {
                if (p == 'W') {
                    p = 'O';
                } else {
                    p = 'X';
                }
            }
        }
    }
    
  private:
    typedef pair<int, int> Point;
    
    const vector<int> dr_ = {-1, 1, 0, 0};
    const vector<int> dc_ = {0, 0, -1, 1};
    
  private:
    void bfs(vector<vector<char>> &board, int r, int c) {
        if (board[r][c] == 'X') {
            return;
        }   
        board[r][c] = 'W';
        
        queue<Point> q;
        q.push({r, c});
        
        while (!q.empty()) {
            Point curr = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = curr.first + dr_[i];
                int nc = curr.second + dc_[i];
                
                if (valid(board, nr, nc)) {
                    board[nr][nc] = 'W';
                    q.push({nr, nc});
                }
            }
        }
    } 
    
    bool valid(const vector<vector<char>> &board, const int r, const int c) {
        return r >= 0 && r < board.size() && 
               c >= 0 && c < board[0].size() &&
               board[r][c] == 'O';
    }
};

