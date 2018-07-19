/*
190. Next Permutation II
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

Example
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

Challenge
The replacement must be in-place, do not allocate extra memory.


Author: Yuan Li
Date: 7/18/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: nothing
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1) 
            return;
            
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
    }
    
    template<typename T>
    void swap(vector<T> &nums, int idx1, int idx2) {
        T temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
};
