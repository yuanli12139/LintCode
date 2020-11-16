/*
588. Partition Equal Subset Sum

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example
Example 1:

Input: nums = [1, 5, 11, 5], 
Output: true

Explanation:
two subsets: [1, 5, 5], [11]

Example 2:

Input: nums = [1, 2, 3, 9], 
Output: false

Notice
Each of the array element will not exceed 100.
The array size will not exceed 200.


Author: Yuan Li
Date: 3/11/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        // write your code here
        int sum = 0;
        for (int &n : nums) {
            sum += n;
        }
        
        // only contain positive ints
        if (sum % 2) {
            return false; 
        }
        
        int m = sum / 2;
        
        // dp[i][s]: before i, sum <= s -> true or false
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        
        dp[0][0] = true;
        for (int i = 1; i < nums.size() + 1; ++i) {
            dp[i%2][0] = true;
            
            for (int s = 1; s < m + 1; ++s) {
                dp[i%2][s] = nums[i-1] <= s ? dp[(i-1)%2][s] || dp[(i-1)%2][s-nums[i-1]] : dp[(i-1)%2][s]; 
            }
        }
        
        return dp[nums.size()%2][m];
    }
};

