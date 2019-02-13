/*
403. Continuous Subarray Sum II

Given an circular integer array (the next element of the last element is the first element), find a continuous subarray in it, where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number.

If duplicate answers exist, return any of them.

Example
Example 1:

Input: [3, 1, -100, -3, 4]
Output: [4, 1]

Example 2:

Input: [1,-1]
Output: [0, 0]

Challenge
O(n) time


Author: Yuan Li
Date: 2/12/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        // write your code here
        Result min_subarr = minMaxSubarraySum(A, true);
        Result max_subarr = minMaxSubarraySum(A);
        
        int cir_sum = pre_sum_ + min_subarr.first; // all negative, cir_sum = 0
        if (cir_sum == 0 || max_subarr.first >= cir_sum) {
            return max_subarr.second;
        }
        return {min_subarr.second[1] + 1, min_subarr.second[0] - 1};
    }
    
  private:
    int pre_sum_;
    typedef pair<int, vector<int>> Result;
    
  private:
    Result minMaxSubarraySum(const vector<int> &A, bool isMin = false) {
        pre_sum_ = 0;
        
        int min_sum = 0, max_sum = INT_MIN;
        int start = 0, end = 0;
        
        Result res = {0, {0, 0}};
        for (int i = 0; i < A.size(); ++i) {
            if (isMin) {
                pre_sum_ -= A[i];
            } else {
                pre_sum_ += A[i];
            }
            
            if (pre_sum_ - min_sum > max_sum) {
                end = i;
                max_sum = pre_sum_ - min_sum;
                    
                res = {max_sum, {start, end}};
            }
            
            if (pre_sum_ < min_sum) {
                start = i + 1;
                min_sum = pre_sum_;
            }
        }
        
        return res;
    }
};

