/*
394. Coins in a Line
There are n coins in a line. Two players take turns to take one or two coins from right side until there are no more coins left. The player who take the last coin wins.

Could you please decide the first play will win or lose?

Example
n = 1, return true.

n = 2, return true.

n = 3, return false.

n = 4, return true.

n = 5, return true.

Challenge
O(n) time and O(1) memory


Author: Yuan Li
Date: 12/11/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        return n % 3;
    }
};


// DP
class Solution {
  public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        if (n == 0) {
            return false;
        }
        
        if (n <= 2) {
            return true;
        }
        
        vector<bool> dp(2, true);
        for (int i = 2; i < n; ++i) {
            dp[i%2] = !dp[(i-1)%2] || !dp[(i-2)%2];
        }
        
        return dp[(n-1)%2];
    }
};

