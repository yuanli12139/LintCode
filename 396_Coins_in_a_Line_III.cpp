/*
396. Coins in a Line III
There are n coins in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins.

Could you please decide the first player will win or lose?

Example
Given array A = [3,2,2], return true.

Given array A = [1,2,4], return true.

Given array A = [1,20,4], return false.

Challenge
Follow Up Question:

If n is even. Is there any hacky algorithm that can decide whether first player will win or lose in O(1) memory and O(n) time?


Author: Yuan Li
Date: 12/16/2018 
Difficulty: Hard
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        if (values.empty()) {
            return false;
        }
        
        int n = values.size();
        
        // max value the 1st player can get within [i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // sum of values within [i, j]
        vector<vector<int>> sum(n, vector<int>(n, 0)); 
        
        // initialization
        for (int i = 0; i < n; ++i) {
            dp[i][i] = values[i];
            sum[i][i] = values[i];
        }
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                sum[i][j] = sum[i+1][j] + values[i]; 
                dp[i][j] = sum[i][j] - min(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] > sum[0][n-1] - dp[0][n-1];
    }
};

