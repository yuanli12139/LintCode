/*
185. Matrix Zigzag Traversal
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.

Example
Given a matrix:

[
  [1, 2,  3,  4],
  [5, 6,  7,  8],
  [9,10, 11, 12]
]

return [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]


Author: Yuan Li
Date: 8/23/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param matrix: An array of integers
     * @return: An array of integers
     */
    vector<int> printZMatrix(vector<vector<int>> &matrix) {
        // write your code here
        vector<int> res;

        if (!matrix.size() || !matrix[0].size()) {
            return res;
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int s = 0; s < n + m - 1; ++s) {
            if (s % 2) {
                for (int c = min(s, m - 1), r = s - c; c >= 0 && r < n; --c, ++r) {
                    res.push_back(matrix[r][c]);
                }
            } else {
                for (int r = min(s, n - 1), c = s - r; r >= 0 && c < m; --r, ++c) {
                    res.push_back(matrix[r][c]);
                }
            }
        }
        
        return res;
    }
};
