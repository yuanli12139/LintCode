/*
89. k Sum

Given n distinct positive integers, integer k (k <= n) and a number target.

Find k numbers where sum is target. Calculate how many solutions there are?

Example
Given [1,2,3,4], k = 2, target = 5.

There are 2 solutions: [1,4] and [2,3].

Return 2.


Author: Yuan Li
Date: 3/17/2019 
Difficulty: Hard
*/

class Solution {
  public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        int n = A.size();
        
        // dp[i][j][s]: before i, pick j nums -> # of possible fill of s
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
        
        dp[0][0][0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            dp[i%2][0][0] = 1;
            
            for (int j = 1; j < k + 1; ++j) {
                for (int s = 1; s <= target; ++s) {
                    // pick A[i-1] or not
                    dp[i%2][j][s] = dp[(i-1)%2][j][s] + (A[i-1] <= s) * dp[(i-1)%2][j-1][s - A[i-1]];
                }
            }
        }
        
        return dp[n%2][k][target];
    }
};

