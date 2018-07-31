/*
405. Submatrix Sum
Given an integer matrix, find a submatrix where the sum of numbers is zero. Your code should return the coordinate of the left-up and right-down number.

Example
Given matrix

[
  [1 ,5 ,7],
  [3 ,7 ,-8],
  [4 ,-8 ,9],
]
return [(1,1), (2,2)]

Challenge
O(n^3) time.


Author: Yuan Li
Date: 7/30/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        // write your code here
        vector<vector<int>> res;
        
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }
        
        // construct prefix-sum matrix
        vector<vector<int>> prefixSum(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int r = 1; r < prefixSum.size(); ++r) {
            for (int c = 1; c < prefixSum[0].size(); ++c) {
                prefixSum[r][c] = prefixSum[r-1][c] + prefixSum[r][c-1] - prefixSum[r-1][c-1] +
                                    matrix[r-1][c-1];
            }
        }
        
        // search for submatrix
        for (int r0 = 0; r0 < prefixSum.size() - 1; ++r0) {
            for (int r1 = r0 + 1; r1 < prefixSum.size(); ++r1) {
                unordered_map<int, int> sum2col;
                for (int c = 0; c < prefixSum[0].size(); ++c) {
                    int submatSum = prefixSum[r1][c] - prefixSum[r0][c];
                    if (sum2col.count(submatSum)) {
                        res = {{r0, sum2col[submatSum]}, {r1 - 1, c - 1}};
                        return res;
                    } else {
                        sum2col[submatSum] = c;
                    }
                }
            }
        }
        
        return res;
    }
};
