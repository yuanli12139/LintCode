/*
476. Stone Game
There is a stone game.At the beginning of the game the player picks n piles of stones in a line.

The goal is to merge the stones in one pile observing the following rules:

At each step of the game,the player can merge two adjacent piles to a new pile.
The score is the number of stones in the new pile.
You are to determine the minimum of the total score.

Example
For [4, 1, 1, 4], in the best solution, the total score is 18:

1. Merge second and third piles => [4, 2, 4], score +2
2. Merge the first two piles => [6, 4]，score +6
3. Merge the last two piles => [10], score +10

Other two examples:
[1, 1, 1, 1] return 8
[4, 4, 5, 9] return 43


Author: Yuan Li
Date: 1/26/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n < 2) {
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> range_sum = getRangeSum(A);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = INT_MAX;
                
                for (int mid = i; mid < j; ++mid) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j] + range_sum[i][j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
  private:
    vector<vector<int>> getRangeSum(const vector<int> &A) {
        int n = A.size();
        vector<vector<int>> range_sum(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            range_sum[i][i] = A[i];
            for (int j = i + 1; j < n; ++j) {
                range_sum[i][j] = range_sum[i][j-1] + A[j];
            }
        }
        
        return range_sum;
    }
};

