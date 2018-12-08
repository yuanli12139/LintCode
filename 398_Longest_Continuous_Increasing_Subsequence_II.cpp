/*
398. Longest Continuous Increasing Subsequence II
Give you an integer matrix (with row size n, column size m)，find the longest increasing continuous subsequence in this matrix. (The definition of the longest increasing continuous subsequence here can start at any row or column and go up/down/right/left any direction).

Example
Given a matrix:

[
  [1 ,2 ,3 ,4 ,5],
  [16,17,24,23,6],
  [15,18,25,22,7],
  [14,19,20,21,8],
  [13,12,11,10,9]
]
return 25

Challenge
O(nm) time and memory.


Author: Yuan Li
Date: 12/7/2018 
Difficulty: Hard
*/

#include <boost/functional/hash.hpp>

class Solution {
  public:
    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        
        int longest = 1;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                longest = max(longest, dfs(matrix, r, c));
            }
        }
        
        return longest;
    }
    
  private:
    unordered_map<pair<int, int>, int, boost::hash<pair<int, int>>> mem_;
  
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    
  private:
    int dfs(const vector<vector<int>> &matrix, int r, int c) {
        if (mem_[{r, c}] > 0) {
            return mem_[{r, c}];
        }        
        
        int longest = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (valid(matrix, nr, nc) && matrix[r][c] < matrix[nr][nc]) {
                longest = max(longest, dfs(matrix, nr, nc) + 1);
            }
        }
        
        mem_[{r, c}] = longest;
        
        return longest; 
    }
    
    bool valid(const vector<vector<int>> &matrix, const int r, const int c) {
        return r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size();
    }
};

