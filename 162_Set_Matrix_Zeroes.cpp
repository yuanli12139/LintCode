/*
162. Set Matrix Zeroes
中文English
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Example
Example 1:

Input:[[1,2],[0,3]]
Output:[[0,2],[0,0]]
Example 2:

Input:[[1,2,3],[4,0,6],[7,8,9]]
Output:[[1,0,3],[0,0,0],[7,0,9]]
Challenge
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


Author: Yuan Li
Date: 12/20/2020
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param matrix: A lsit of lists of integers
     * @return: nothing
     */
    void setZeroes(vector<vector<int>> &matrix) {
        // write your code here
        if (matrix.empty() or matrix[0].empty()) {
            return;
        } 
        
        bool r0 = false;
        bool c0 = false;
        
        for (int r = 0; r < matrix.size(); ++r) {
            if (matrix[r][0] == 0) {
                r0 = true;
                break;
            }
        }
        for (int c = 0; c < matrix[0].size(); ++c) {
            if (matrix[0][c] == 0) {
                c0 = true;
                break;
            }
        } 
            
        for (int r = 1; r < matrix.size(); ++r) {    
            for (int c = 1; c < matrix[0].size(); ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        
        for (int r = 1; r < matrix.size(); ++r) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < matrix[0].size(); ++c) {
                    matrix[r][c] = 0;
                }
            }
        }
        
        for (int c = 1; c < matrix[0].size(); ++c) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < matrix.size(); ++r) {
                    matrix[r][c] = 0;
                }
            }
        }
        
        if (r0) {
            for (int r = 0; r < matrix.size(); ++r) {
                matrix[r][0] = 0;
            }
        }
        
        if (c0) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                matrix[0][c] = 0;
            }
        }
    }
};
