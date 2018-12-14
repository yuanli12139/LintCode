/*
395. Coins in a Line II
There are n coins with different value in a line. Two players take turns to take one or two coins from left side until there are no more coins left. The player who take the coins with the most value wins.

Could you please decide the first player will win or lose?

Example
Given values array A = [1,2,2], return true.

Given A = [1,2,4], return false.


Author: Yuan Li
Date: 12/14/2018 
Difficulty: Medium
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
        
        if (values.size() <= 2) {
            return true;
        }
       
        int n = values.size();
        
        vector<int> dp(3, 0);
        dp[(n-1)%3] = values[n-1];
        dp[(n-2)%3] = values[n-2] + values[n-1];
        
        vector<int> post_sum(3, 0);
        post_sum[(n-1)%3] = values[n-1];
        post_sum[(n-2)%3] = values[n-1] + values[n-2];
        
        for (int i = n - 3; i >= 0; --i) {
            post_sum[i%3] = post_sum[(i+1)%3] + values[i];
            
            // after 1st player took the coin(s), the 2nd player becomes 1st player
            dp[i%3] = max(values[i] + post_sum[(i+1)%3] - dp[(i+1)%3], 
                        values[i] + values[i+1] + post_sum[(i+2)%3] - dp[(i+2)%3]);
        }

        return dp[0] > post_sum[0] - dp[0];
    }
};

