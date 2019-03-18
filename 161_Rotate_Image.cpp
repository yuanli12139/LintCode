/*
161. Rotate Image

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Example
Example 1：

Input:[[1,2],[3,4]]
Output:[[3,1],[4,2]]

Example 2:

Input:[[1,2,3],[4,5,6],[7,8,9]]
Output:[[7,4,1],[8,5,2],[9,6,3]]

Challenge
Do it in-place.


Author: Yuan Li
Date: 3/17/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param matrix: a lists of integers
     * @return: nothing
     */
    void rotate(vector<vector<int>> &matrix) {
        // write your code here
        int n = matrix.size();
        
        for (int r = 0; r < (n + 1) / 2; ++r) {
            for (int c = 0; c < n / 2; ++c) {
                int tmp = matrix[r][c];
                matrix[r][c] = matrix[n-1-c][r];
                matrix[n-1-c][r] = matrix[n-1-r][n-1-c];
                matrix[n-1-r][n-1-c] = matrix[c][n-1-r];
                matrix[c][n-1-r] = tmp;
            }
        }
    }
};

