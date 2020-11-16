/*
362. Sliding Window Maximum
Given an array of n integer with duplicate number, and a moving window(size k), move the window at each iteration from the start of the array, find the maximum number inside the window at each moving.

Example
For array [1, 2, 7, 7, 8], moving window size k = 3. return [7, 7, 8]

At first the window is at the start of the array like this

[|1, 2, 7| ,7, 8] , return the maximum 7;

then the window move one step forward.

[1, |2, 7 ,7|, 8], return the maximum 7;

then the window move one step forward again.

[1, 2, |7, 7, 8|], return the maximum 8;

Challenge
o(n) time and O(k) memory


Author: Yuan Li
Date: 11/25/2018 
Difficulty: Hard
*/

class Solution {
  public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        if (nums.empty() || k <= 0) {
            return {};
        }
        
        for (int i = 0; i < k - 1; ++i) {
            push(nums, i);
        }
        
        vector<int> res;
        for (int i = k - 1; i < nums.size(); ++i) {
            push(nums, i);
            res.push_back(nums[dq_[0]]);
            
            // maintain dq_.size() = k - 1
            if (dq_[0] == i - k + 1) {
                dq_.pop_front();
            }
        }
        
        return res;
    }
    
  private:
    deque<int> dq_; // index of decending num
    
  private:
    void push(const vector<int> &nums, int index) {
        while (!dq_.empty() && nums[dq_.back()] < nums[index]) {
            dq_.pop_back();
        }
        dq_.push_back(index);
    }
};

