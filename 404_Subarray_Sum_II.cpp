/*
404. Subarray Sum II

Given an integer array, find a subarray where the sum of numbers is in a given interval. Your code should return the number of possible answers. (The element in the array should be positive)

Example
Given [1,2,3,4] and interval = [1,3], return 4. The possible answers are:

[0, 0]
[0, 1]
[1, 1]
[2, 2]


Author: Yuan Li
Date: 2/10/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        // write your code here
        int n = A.size();
        
        int small_end = 0, big_end = 0;
        int small_sum = 0, big_sum = 0;
        
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            small_end = max(small_end, i);
            big_end = max(big_end, i);
            
            while (small_end < n && small_sum + A[small_end] < start) {
                small_sum += A[small_end++];
            }
            while (big_end < n && big_sum + A[big_end] <= end) {
                big_sum += A[big_end++];
            }
            
            res += max(0, big_end - small_end);
            
            if (small_end > i) { // small_end moved
                small_sum -= A[i]; // move i
            }
            if (big_end > i) { // big_end moved
                big_sum -= A[i]; // move i
            }
        }
        
        return res;
    }
};

