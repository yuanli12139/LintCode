/*
817. Range Sum Query 2D - Mutable
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

1.The matrix is only modifiable by the update function.
2.You may assume the number of calls to update and sumRegion function is distributed evenly.
3.You may assume that row1 ≤ row2 and col1 ≤ col2.

Example
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10


Author: Yuan Li
Date: 7/31/2018 
Difficulty: Medium
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        mat.resize(matrix.size(), vector<int>(matrix[0].size()));
        bit.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                update(r, c, matrix[r][c]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - mat[row][col];
        mat[row][col] = val;
        
        for (int r = row + 1; r <= mat.size(); r += lowBit(r)) {
            for (int c = col + 1; c <= mat[0].size(); c += lowBit(c)) {
                bit[r][c] += delta;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getPrefixMatSum(row2, col2) - getPrefixMatSum(row2, col1-1) -
                getPrefixMatSum(row1-1, col2) + getPrefixMatSum(row1-1, col1-1);
    }
    
    int getPrefixMatSum(int row, int col) {
        int prefixMatSum = 0; 
        for (int r = row + 1; r > 0; r -= lowBit(r)) {
            for (int c = col + 1; c > 0; c -= lowBit(c)) {
                prefixMatSum += bit[r][c];
            }
        }
        
        return prefixMatSum;
    }
    
    int lowBit(int x) {
        return x & (-x);
    }
    
private:
    vector<vector<int>> mat, bit;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
 