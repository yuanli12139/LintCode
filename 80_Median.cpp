/*
80. Median
Given a unsorted array with integers, find the median of it.

A median is the middle number of the array after it is sorted.

If there are even numbers in the array, return the N/2-th number after sorted.

Example
Given [4, 5, 1, 2, 3], return 3.

Given [7, 9, 4, 5], return 5.

Challenge
O(n) time.


Author: Yuan Li
Date: 7/30/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the middle number of the array
     */
    int median(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        
        if (n % 2 == 0) {
            return quickSelect(nums, 0, nums.size() - 1, n / 2);           
            // return (quickSelect(nums, start, end, n / 2) + 
            //         quickSelect(nums, start, end, n / 2 + 1)) / 2.;
        }
        
        return quickSelect(nums, 0, nums.size() - 1, n / 2 + 1);
    }
    
    int quickSelect(vector<int> &nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }
        
        int i = start, j = end;
        int pivot = nums[(i + j) / 2];
        
        while (i <= j) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }
            
            while (i <= j && nums[j] > pivot) {
                j--;
            }
            
            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
            
        }
            
        if (j - start + 1 >= k) {
            return quickSelect(nums, start, j, k);
        }
        
        if (i - start + 1 <= k) {
            return quickSelect(nums, i, end, k - (i - start));
        }
        
        return nums[j+1];
    }
};
