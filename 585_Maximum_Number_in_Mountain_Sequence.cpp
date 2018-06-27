/*
585. Maximum Number in Mountain Sequence
Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.

Example
Given nums = [1, 2, 4, 8, 6, 3] return 8
Given nums = [10, 9, 8, 7], return 10


Author: Yuan Li
Date: 6/26/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2; // avoid int overflow
            if (nums[mid] < nums[mid+1]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        return max(nums[start], nums[end]);
    }
};
