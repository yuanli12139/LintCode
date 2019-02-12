/*
402. Continuous Subarray Sum

Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return the minimum one in lexicographical order)

Example
Example 1:

Input: [-3, 1, 3, -3, 4]
Output: [1, 4]

Example 2:

Input: [0, 1, 0, 1]
Output: [0, 3]
Explanation: The minimum one in lexicographical order.


Author: Yuan Li
Date: 2/11/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        // write your code here
        int pre_sum = 0;
        int min_sum = 0, max_sum = INT_MIN;
        int start = 0, end = 0;
        
        vector<int> res = {0, 0};
        for (int i = 0; i < A.size(); ++i) {
            pre_sum += A[i];
            
            if (pre_sum - min_sum > max_sum) {
                end = i;
                max_sum = pre_sum - min_sum;
                
                res = {start, end};
            }
            
            if (pre_sum < min_sum) {
                start = i + 1;
                min_sum = pre_sum;
            }
        }
        
        return res;
    }
};

