/*
406. Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return -1 instead.

Example
Given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length under the problem constraint.

Challenge
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).


Author: Yuan Li
Date: 9/18/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        if (nums.empty()) {
            return -1;
        }
        
        int pre_sum = 0;
        int n = nums.size();
        int min_len = n + 1;
        
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && pre_sum < s) {
                pre_sum += nums[j++];
            }
            
            // constraint satisfied
            if (pre_sum >= s) {
                min_len = min(min_len, j - i);
            } else {
                break;
            }
            
            pre_sum -= nums[i];
        }
        
        return min_len == n + 1 ? -1 : min_len;
    }
};

