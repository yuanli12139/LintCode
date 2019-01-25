/*
663. Walls and Gates
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a ROOM, that room should remain filled with INF.

Example
Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
  
return the result:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4


Author: Yuan Li
Date: 1/24/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }
        
        queue<Point> q;
        for (int r = 0; r < rooms.size(); ++r) {
            for (int c = 0; c < rooms[0].size(); ++c) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        
        while (!q.empty()) {
            Point curr = q.front();
            q.pop();
            
            int r = curr.first;
            int c = curr.second;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr_[i];
                int nc = c + dc_[i];
                
                if (valid(rooms, nr, nc)) {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    
  private:
    typedef pair<int, int> Point;
    
    const vector<int> dr_ = {-1, 1, 0, 0};
    const vector<int> dc_ = {0, 0, -1, 1};
    
  private:
    bool valid(const vector<vector<int>> &rooms, const int r, const int c) {
        return r >= 0 && r < rooms.size() &&
               c >= 0 && c < rooms[0].size() &&
               rooms[r][c] == INT_MAX;
    }
};

