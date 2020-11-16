/*
1318. Contains Duplicate III
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example
Given nums = [1,3,1], k = 1, t = 1, return false.


Author: Yuan Li
Date: 9/29/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @param t: the given t
     * @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
     */
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        // Write your code here
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                win_.erase(nums[i-k-1]);
            }
            
            // check if -t <= x - nums[i] <= t
            auto it = win_.lower_bound(nums[i] - t); // x - nums[i] >= -t
            if (it != win_.end() && *it - nums[i] <= t) { // x - nums[i] <= t
                return true;
            }
            
            win_.insert(nums[i]);
        }
        
        return false;
    }

  private:
    set<int> win_;
};

