/*
52. Next Permutation
Given a list of integers, which denote a permutation.

Find the next permutation in ascending order.

The list may contains duplicate integers.

Example
For [1,3,2,3], the next permutation is [1,3,3,2]

For [4,3,2,1], the next permutation is [1,2,3,4]


Author: Yuan Li
Date: 7/18/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1) 
            return nums;
            
        // first non-decending from right
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        
        if (i != 0) {
            // on the right of nums[i-1], first item greater than nums[i-1] from right
            int j = nums.size() - 1;
            while (i < j && nums[i-1] >= nums[j]) {
                j--;
            }
            
            swap(nums, i-1, j);
            reverse(nums.begin() + i, nums.end());
        }
        
        else {
            reverse(nums.begin(), nums.end());
        }
        
        return nums;
    }
    
    template<typename T>
    void swap(vector<T> &nums, int idx1, int idx2) {
        T temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
};
