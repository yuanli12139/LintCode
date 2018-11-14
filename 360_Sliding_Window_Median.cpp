/*
360. Sliding Window Median
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, find the median of the element inside the window at each moving. (If there are even numbers in the array, return the N/2-th number after sorting the element in the window. )

Example
For array [1,2,7,8,5], moving window size k = 3. return [2,7,7]

At first the window is at the start of the array like this

[ | 1,2,7 | ,8,5] , return the median 2;

then the window move one step forward.

[1, | 2,7,8 | ,5], return the median 7;

then the window move one step forward again.

[1,2, | 7,8,5 | ], return the median 7;

Challenge
O(nlog(n)) time

Reference
https://zxi.mytechroad.com/blog/difficulty/hard/leetcode-480-sliding-window-median/


Author: Yuan Li
Date: 11/14/2018 
Difficulty: Hard
*/

// insertion sort - O(max(k*log(k), (n-k)*k))
class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> medians;
        if (k == 0) {
            return medians;
        } 
        
        vector<int> win(nums.begin(), nums.begin() + k - 1); // first k-1 nums
        
        sort(win.begin(), win.end());
        
        // insertion sort
        for (int i = k - 1; i < nums.size(); ++i) {
            win.push_back(nums[i]);
            
            auto it = prev(win.end(), 1);
            auto const it_insert = upper_bound(win.begin(), it, *it);
            rotate(it_insert, it, win.end());
            
            medians.push_back(win[(k-1)/2]);
            
            auto it_erase = lower_bound(win.begin(), win.end(), nums[i-k+1]);
            win.erase(it_erase);
        }
        
        return medians;
    }
};

