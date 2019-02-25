/*
507. Wiggle Sort II

Given an unsorted array nums, reorder it such that

nums[0] < nums[1] > nums[2] < nums[3]....

Example
Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].

Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Challenge
Can you do it in O(n) time and/or in-place with O(1) extra space?

Notice
You may assume all input has valid answer.


Author: Yuan Li
Date: 2/24/2019 
Difficulty: Hard
*/

class Solution {
  public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int m = (n - 1) / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        int median = nums[m];
        
        // i (odd): nums[i] < median
        // i (even): nums[i] > median
        int i = 0, o = 1, e = (n - 1) % 2 == 0 ? n - 1 : n - 2;
        while (i < n) { 
            if (nums[i] > median && (i % 2 == 0 || i > o)) {
                swap(nums[i], nums[o]);
                o += 2;
                continue;
            }
            
            if (nums[i] < median && (i % 2 == 1 || i < e)) {
                swap(nums[i], nums[e]);
                e -= 2;
                continue;
            }
            
            ++i;
        } 
    }
};

