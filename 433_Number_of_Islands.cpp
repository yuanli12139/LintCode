/*
433. Number of Islands
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.

Example
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.


Author: Yuan Li
Date: 6/26/2018 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        int islands = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c]) {
                    grid[r][c] = false;
                    BFSVisit(grid, r, c);
                    islands++;
                }
            }
        }

        return islands;
    }
    
  private:
    vector<int> dr_ = {-1, 1, 0, 0};
    vector<int> dc_ = {0, 0, -1, 1};
    queue<pair<int, int>> q_;
    
  private:
    void BFSVisit(vector<vector<bool>> &grid, int r, int c) {
        q_.push(pair<int, int> (r, c));
        
        while (!q_.empty()) {
            pair<int, int> curr = q_.front();
            q_.pop();
        
            for (int d = 0; d < 4; d++) {
                int next_r = curr.first + dr_[d];
                int next_c = curr.second + dc_[d];
                
                if (isValid(grid, next_r, next_c)) {
                    grid[next_r][next_c] = false;
                    q_.push(pair<int, int> (next_r, next_c));
                }
            }
        }
    }
    
    bool isValid(vector<vector<bool>> &grid, int r, int c) {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size())
            return grid[r][c];
        
        return false; 
    }
};
