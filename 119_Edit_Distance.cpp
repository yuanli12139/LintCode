/*
119. Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example
Given word1 = "mart" and word2 = "karma", return 3.


Author: Yuan Li
Date: 1/30/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int n = word1.length(), m = word2.length();
        
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        for (int j = 1; j < m + 1; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i < n + 1; ++i) {
            dp[i%2][0] = i;
            
            for (int j = 1; j < m + 1; ++j) {
                dp[i%2][j] = min(dp[(i-1)%2][j] + 1, dp[i%2][j-1] + 1); // delete, insert
                
                if (word1[i-1] == word2[j-1]) {
                    dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j-1]);
                } else {
                    dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j-1] + 1); // replace
                }
            }
        }
        
        return dp[n%2][m];
    }
};

