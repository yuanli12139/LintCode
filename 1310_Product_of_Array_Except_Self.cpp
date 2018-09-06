/*
1310. Product of Array Except Self
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example
For example, given [1,2,3,4], return [24,12,8,6].

Challenge
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Notice
Solve it without division and in O(n).


Author: Yuan Li
Date: 9/5/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the product of all the elements of nums except nums[i].
     */
    vector<int> productExceptSelf(vector<int> &nums) {
        // write your code here
        vector<int> left_prod(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            left_prod[i] = left_prod[i-1] * nums[i-1]; // product before nums[i]
        }
        
        int right_prod = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            left_prod[i] *= right_prod;
            right_prod *= nums[i];
        }
        
        return left_prod;
    }
};
