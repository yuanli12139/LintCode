/*
125. Backpack II

Given n items with size Ai and value Vi, and a backpack with size m. What's the maximum value can you put into the backpack?

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.

Challenge
O(n x m) memory is acceptable, can you do it in O(m) memory?

Notice
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.


Author: Yuan Li
Date: 3/13/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        
        // dp[i][s]: before item i, size <= s -> maximum value
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        
        dp[0][0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            dp[i%2][0] = 0;
            
            for (int s = 1; s < m + 1; ++s) {
                dp[i%2][s] = dp[(i-1)%2][s];
                
                if (A[i-1] <= s) {
                    dp[i%2][s] = max(dp[(i-1)%2][s], dp[(i-1)%2][s - A[i-1]] + V[i-1]);
                }
            }
        }
        
        return dp[n%2][m];
    }
};

