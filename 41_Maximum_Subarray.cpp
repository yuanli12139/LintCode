/*
41. Maximum Subarray
Given an array of integers, find a contiguous subarray which has the largest sum.

The subarray should contain at least one number.

Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Challenge
Can you do it in time complexity O(n)?


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
