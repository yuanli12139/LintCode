/*
654. Sparse Matrix Multiplication
Given two Sparse Matrix A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        // write your code here
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        
        vector<vector<pair<int, int>>> sparseA; // rows of A
        for (auto &row : A) {
            vector<pair<int, int>> sparseRow;
            for (int c = 0; c < row.size(); ++c) {
                if (row[c] != 0) {
                    sparseRow.push_back(make_pair(c, row[c]));
                }
            }
            
            sparseA.push_back(sparseRow);
        }
        
        vector<vector<pair<int, int>>> sparseB; // columns of B
        for (int c = 0; c < B[0].size(); ++c) {
            vector<pair<int, int>> sparseCol;
            for (int r = 0; r < B.size(); ++r) {
                if (B[r][c] != 0) {
                    sparseCol.push_back(make_pair(r, B[r][c]));
                }
            }
            
            sparseB.push_back(sparseCol);
        }
        
        for (int r = 0; r < sparseA.size(); ++r) {
            for (int c = 0; c < sparseB.size(); ++c) {
                res[r][c] = dotProduct(sparseA[r], sparseB[c]);
            }
        }
        
        return res;
    }
    
  private:
    int dotProduct(const vector<pair<int, int>> &vec1, const vector<pair<int, int>> &vec2) {
        int res = 0;
        
        if (vec1.empty() || vec2.empty()) {
            return res;
        }
        
        int i = 0, j = 0;
        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i].first < vec2[j].first) {
                i++;
                continue;
            }
            
            if (vec1[i].first > vec2[j].first) {
                j++;
                continue;
            }
            
            res += vec1[i++].second * vec2[j++].second;
        }
        
        return res;
    }
};


// Date: 3/19/2019
class Solution {
  public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        // write your code here
        int n = A.size();
        int m = B[0].size();
        int t = B.size();
        
        vector<vector<int>> res(n, vector<int>(m, 0));
        
        unordered_map<int, vector<int>> non_zero_cols;
        for (int r = 0; r < t; ++r) {
            for (int c = 0; c < m; ++c) {
                if (B[r][c] != 0) {
                    non_zero_cols[r].push_back(c);
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < t; ++k) {
                if (A[i][k] == 0) {
                    continue;
                }
                
                for (int j : non_zero_cols[k]) {
                    res[i][j] += A[i][k] * B[k][j]; 
                }
            }
        }
        
        return res;
    }
};

