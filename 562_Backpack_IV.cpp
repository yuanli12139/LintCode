/*
562. Backpack IV

Given an integer array nums[] which contains n unique positive numbers, num[i] indicate the size of ith item. An integer target denotes the size of backpack. Find the number of ways to fill the backpack.

Each item may be chosen unlimited number of times

Example
Example1

Input: nums = [2,3,6,7] and target = 7
Output: 2
Explanation:
Solution sets are: 
[7]
[2, 2, 3]

Example2

Input: nums = [2,3,4,5] and target = 7
Output: 2
Explanation:
Solution sets are: 
[2, 5]
[3, 4]


Author: Yuan Li
Date: 3/15/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        // dp[i][s]: before i -> # of possible fill of s
        // dp[i][s] = dp[i-1][s] + dp[i-1][s - nums[i-1]] 
        //          + dp[i-1][s - 2*nums[i-1]] + ... till s - a*nums[i-1] < 0
        //          = dp[i-1][s] + dp[i][s - nums[i-1]]
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            dp[i][0] = 1;
            
            for (int s = 1; s <= target; ++s) {
                dp[i][s] = dp[i-1][s] + dp[i][s - nums[i-1]] * (nums[i-1] <= s);
            }
        }
        
        return dp[n][target];
    }
};

