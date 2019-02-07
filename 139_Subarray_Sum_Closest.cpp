/*
139. Subarray Sum Closest
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Example
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].

Challenge
O(nlogn) time

Author: Yuan Li
Date: 7/27/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<int> res;
        
        vector<int> sums = {0};
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum2idx.count(sum)) {
                res = {sum2idx[sum] + 1, i};
                return res;
            }
            
            sums.push_back(sum);
            sum2idx[sum] = i;
        }
        
        sort(sums.begin(), sums.end());
        
        int closest_sum = INT_MAX, idx1, idx2;
        for (int j = 0; j + 1 < sums.size(); ++j) {
            int subarr_sum = sums[j+1] - sums[j];
            if (subarr_sum <= closest_sum) { // = for subarr_sum == INT_MAX
                closest_sum = subarr_sum;
                idx1 = sum2idx[sums[j]];
                idx2 = sum2idx[sums[j+1]];
            }
        }
        
        res = {min(idx1, idx2) + 1, max(idx1, idx2)};
        
        return res;
    }
};


// Data: 2/2/2019
class Solution {
  public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<pair<int, int>> pre_sum = {{0, -1}}; // prefix sum -> index
        for (int i = 0; i < nums.size(); ++i) {
            pre_sum.emplace_back(pre_sum.back().first + nums[i], i);
        }
        
        sort(pre_sum.begin(), pre_sum.end());
        
        int min_sum = INT_MAX;
        vector<int> res;
        for (int i = 1; i < pre_sum.size(); ++i) {
            int left_id = min(pre_sum[i-1].second, pre_sum[i].second) + 1; 
            int right_id = max(pre_sum[i-1].second, pre_sum[i].second); 
            
            if (res.empty()) {
                res.push_back(left_id);
                res.push_back(right_id);
                continue;
            }
            
            if (pre_sum[i].first - pre_sum[i-1].first < min_sum) {
                res[0] = left_id;
                res[1] = right_id;
                
                min_sum = pre_sum[i].first - pre_sum[i-1].first;
            }
        }
        
        return res;
    }
};

