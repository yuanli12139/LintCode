/*
5. Kth Largest Element

Find K-th largest element in an array.

Example
Example 1:

Input:
n = 1, nums = [1,3,4,2]
Output:
4

Example 2:

Input:
n = 3, nums = [9,3,2,4,8]
Output:
4

Challenge
O(n) time, O(1) extra memory.

Notice
You can swap elements in the array


Author: Yuan Li
Date: 2/20/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        if (nums.empty() || n < 1 || n > nums.size()) {
            return -1;
        }
        
        return quickSelect(n, nums, 0, nums.size() - 1);
    }
  
  private:
    int quickSelect(int k, vector<int> &nums, int start, int end) {
        int left = start, right = end;
        int pivot = nums[(end - start) / 2 + start];
        
        while (left <= right) {
            while (left <= right && nums[left] > pivot) {
                ++left;
            }
            while (left <= right && nums[right] < pivot) {
                --right;
            }
            
            if (left <= right) {
                int tmp = nums[left];
                nums[left++] = nums[right];
                nums[right--] = tmp;
            }
        }
        
        if (start + k - 1 <= right) {
            return quickSelect(k, nums, start, right);
        }
        if (start + k - 1 >= left) {
            return quickSelect(k - (left - start), nums, left, end);
        }
        return nums[right+1];
    }
};

