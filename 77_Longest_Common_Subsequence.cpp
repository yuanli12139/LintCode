/*
77. Longest Common Subsequence
Given two strings, find the longest common subsequence (LCS).

Your code should return the length of LCS.

Example
For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

For "ABCD" and "EACB", the LCS is "AC", return 2.

Clarification
What's the definition of Longest Common Subsequence?

https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
http://baike.baidu.com/view/2020307.htm


Author: Yuan Li
Date: 1/28/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        int n = A.size(), m = B.size();
        
        // dp[i][j]: LCS before #i in A and #j in B
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                if (A[i-1] == B[j-1]) {
                    dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
                } else {
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
                }
            }
        }
        
        return dp[n%2][m];
    }
};

