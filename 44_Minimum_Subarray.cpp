/*
44. Minimum Subarray
Given an array of integers, find the subarray with smallest sum.

The subarray should contain one integer at least.

Return the sum of the subarray.

Example
For [1, -1, -2, 1], return -3.

Author: Yuan Li
Date: 7/27/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }
        
        int max_sum = INT_MIN, sum = 0, min_sum = 0;
        for (int n : nums) {
            sum += n;
            max_sum = max(max_sum, sum - min_sum);
            min_sum = min(min_sum, sum);
        }
        
        return max_sum;
    }
};
