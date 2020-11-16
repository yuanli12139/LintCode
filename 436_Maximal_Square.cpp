/*
436. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

Example
For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.


Author: Yuan Li
Date: 12/3/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        
        // initialize
        // at (r, c) as right-bottom corner, length of the maximal all-1 square 
        vector<vector<int>> dp(2, vector<int> (m, 0)); 
        int max_edge = 0;
        for (int c = 0; c < m; ++c) {
            dp[0][c] = matrix[0][c];    
            max_edge = max(max_edge, dp[0][c]);
        }
        
        for (int r = 1; r < n; ++r) {
            dp[r%2][0] = matrix[r][0];
            max_edge = max(max_edge, dp[r%2][0]);
            
            for (int c = 1; c < m; ++c) {
                if (matrix[r][c]) {
                    dp[r%2][c] = min(dp[(r-1)%2][c-1], min(dp[(r-1)%2][c], dp[r%2][c-1])) + 1;
                } else {
                    dp[r%2][c] = 0;
                }
                
                max_edge = max(max_edge, dp[r%2][c]);
            }
        }
        
        return max_edge * max_edge;
    }
};

