/*
138. Subarray Sum
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

There is at least one subarray that it's sum equals to zero.

Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

Author: Yuan Li
Date: 7/27/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        vector<int> res;

        int sum = 0;        
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum2idx.count(sum)) {
                res.push_back(sum2idx[sum] + 1);
                res.push_back(i);
            }
            
            sum2idx[sum] = i;
        }
        
        return res;
    }
};
