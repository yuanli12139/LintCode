/*
397. Longest Continuous Increasing Subsequence
Give an integer array，find the longest increasing continuous subsequence in this array.

An increasing continuous subsequence:

Can be from right to left or from left to right.
Indices of the integers in the subsequence should be continuous.
Example
For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.

For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.

Challenge
O(n) time and O(1) extra space.


Author: Yuan Li
Date: 12/5/2018 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        if (A.empty()) {
            return 0;
        }
        
        int res = 1;
        int inc = 1, dec = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i-1]) {
                ++inc;
                dec = 1;
            } else if (A[i] < A[i-1]) {
                inc = 1;
                ++dec;
            } else {
                inc = 1;
                dec = 1;
            }
            
            res = max(res, max(inc, dec));
        }
        
        return res;
    }
};

