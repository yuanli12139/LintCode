/*
665. Range Sum Query 2D - Immutable
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.

Example
Given matrix =

[
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12


Author: Yuan Li
Date: 7/31/2018 
Difficulty: Medium
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        prefix_sum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        
        for (int r = 0; r < matrix.size(); ++r) {
            int row_sum = 0;
            for (int c = 0; c < matrix[0].size(); ++c) {
                row_sum += matrix[r][c];
                prefix_sum[r+1][c+1] = prefix_sum[r][c+1] + row_sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix_sum[row2+1][col2+1] - prefix_sum[row1][col2+1] - 
                prefix_sum[row2+1][col1] + prefix_sum[row1][col1];
    }
    
private:
    vector<vector<int>> prefix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
 