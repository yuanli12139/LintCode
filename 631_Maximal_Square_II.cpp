/*
631. Maximal Square II
Given a 2D binary matrix filled with 0's and 1's, find the largest square which diagonal is all 1 and others is 0.

Example
For example, given the following matrix:

1 0 1 0 0
1 0 0 1 0
1 1 0 0 1
1 0 0 1 0
Return 9

Notice
Only consider the main diagonal situation.


Author: Yuan Li
Date: 12/4/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(2, vector<int>(m, 0));
        vector<vector<int>> up(2, vector<int>(m, 0));
        
        int max_edge = 0;
        for (int c = 0; c < m; ++c) {
            dp[0][c] = matrix[0][c];
            up[0][c] = matrix[0][c] ? 0 : 1;
            
            max_edge = max(max_edge, matrix[0][c]);
        }
        
        for (int r = 1; r < n; ++r) {
            dp[r%2][0] = matrix[r][0];
            up[r%2][0] = matrix[r][0] ? 0 : matrix[r-1][0] + 1;
            int left = 0;
            
            max_edge = max(max_edge, matrix[r][0]); 
            
            for (int c = 1; c < m; ++c) {
                if (matrix[r][c]) {
                    dp[r%2][c] = min(dp[(r-1)%2][c-1], min(up[(r-1)%2][c], left)) + 1;
                    up[r%2][c] = 0;
                    left = 0;
                } else {
                    dp[r%2][c] = 0;
                    up[r%2][c] = up[(r-1)%2][c] + 1;
                    left += 1;
                }
                
                max_edge = max(max_edge, dp[r%2][c]);
            }
        }
        
        return max_edge * max_edge;
    }
};

