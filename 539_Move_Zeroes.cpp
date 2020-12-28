/*
539. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Example
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].


Author: Yuan Li
Date: 7/4/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int start0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[start0++] = nums[i];
            }
        }
        
        fill(nums.begin() + start0, nums.end(), 0);
    }
};
