/*
508. Wiggle Sort

Given an unsorted array nums, reorder it in-place such that

nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example
Example 1:

Input: [3, 5, 2, 1, 6, 4]
Output: [1, 6, 2, 5, 3, 4]
Explanation: This question may have multiple answers, and [2, 6, 1, 5, 3, 4] is also ok.
Example 2:

Input: [1, 2, 3, 4]
Output: [2, 1, 4, 3]

Notice
Please complete the problem in-place.


Author: Yuan Li
Date: 2/22/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return;
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            bool do_swap = i % 2 ? nums[i-1] > nums[i] : nums[i-1] < nums[i];
            
            if (do_swap) {
                int tmp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = tmp;
            }
        }
    }
};

