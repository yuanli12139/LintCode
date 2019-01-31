/*
92. Backpack
Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.

Challenge
O(n x m) time and O(m) memory.

O(n x m) memory is also acceptable if you do not know how to optimize memory.

Notice
You can not divide any item into small pieces.


Author: Yuan Li
Date: 1/31/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        
        // dp[i][s]: before i, size <= s -> true or false
        vector<vector<bool>> dp(2, vector<bool>(m + 1, 0));
        
        dp[0][0] = true;
        for (int i = 1; i < n + 1; ++i) {
            dp[i%2][0] = true;
            
            for (int s = 1; s < m + 1; ++s) {
                if (s >= A[i-1]) {
                    dp[i%2][s] = dp[(i-1)%2][s] || dp[(i-1)%2][s - A[i-1]]; // pick A[i-1] or not
                } else {
                    dp[i%2][s] = dp[(i-1)%2][s];
                }
            }
        } 
        
        for (int s = m; s >= 0; --s) {
            if (dp[n%2][s]) {
                return s;
            }
        }
        return 0;
    }
};

