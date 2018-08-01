/*
943. Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

You may assume that the array does not change.
There are many calls to sumRange function.

Example
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3


Author: Yuan Li
Date: 7/31/2018 
Difficulty: Easy
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        prefix_sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            prefix_sum.push_back(prefix_sum.back() + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return prefix_sum[j];    
        }
        
        return prefix_sum[j] - prefix_sum[i-1];
    }
    
private:
    vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
 