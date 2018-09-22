/*
461. Kth Smallest Numbers in Unsorted Array
Find the kth smallest number in an unsorted integer array.

Example
Given [3, 4, 1, 2, 5], k = 3, the 3rd smallest numbers is 3.

Challenge
An O(nlogn) algorithm is acceptable, if you can do it in O(n), that would be great.


Author: Yuan Li
Date: 9/21/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        // write your code here
        return quickSelect(k - 1, nums, 0, nums.size() - 1);
    }
    
  private:
    int quickSelect(int k, vector<int> &nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        
        int i = start, j = end;
        int pivot = nums[start + (end - start) / 2];
        
        while (i <= j) {
            while (i <= j && nums[i] < pivot) {
                ++i;
            }
            while (i <= j && nums[j] > pivot) {
                --j;
            }
            
            if (i <= j) {
                int temp = nums[i];
                nums[i++] = nums[j];
                nums[j--] = temp;
            } 
        }
        
        if (start <= j && k <= j) { // go left
            return quickSelect(k, nums, start, j);
        }
        if (end >= i && k >= i) { // go right
            return quickSelect(k, nums, i, end);
        }
        return nums[k]; // j + 1 == k == i - 1
    }
};
