/*
944. Maximum Submatrix
Given an n x n matrix of positive and negative integers, find the submatrix with the largest possible sum.

Example
Given matrix = 
[
[1,3,-1],
[2,3,-2],
[-1,-2,-3]
]
return 9.

Explanation:
the submatrix with the largest possible sum is:
[
[1,2],
[2,3]
]


Author: Yuan Li
Date: 7/31/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        vector<vector<int>> prefixColSum = getPrefixColSum(matrix);
    
        int res = INT_MIN;
        for (int up = 0; up < matrix.size(); ++up) {
            for (int down = up; down < matrix.size(); ++down) {
                vector<int> arr = sumCol(matrix, up, down, prefixColSum);
                int curr_sum = maxSubArrSum(arr);
                res = max(res, curr_sum);
            }
        }

        return res;
    }
    
    // compute prefix sum for each column
    vector<vector<int>> getPrefixColSum(const vector<vector<int>> &matrix) {
        vector<vector<int>> prefix_sum(matrix.size() + 1, vector<int>(matrix[0].size(), 0));
        
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                prefix_sum[r+1][c] = prefix_sum[r][c] + matrix[r][c];
            }
        }
        
        return prefix_sum;
    }
    
    // sum up sub-columns to form an array
    vector<int> sumCol(const vector<vector<int>> &matrix, int up, int down, 
                        const vector<vector<int>> &prefixColSum) {
        vector<int> arr;
        
        for (int c = 0; c < matrix[0].size(); ++c) {
            arr.push_back(prefixColSum[down+1][c] - prefixColSum[up][c]);
        }
        
        return arr;
    }
    
    // compute maximum subarray sum
    int maxSubArrSum(const vector<int> &arr) {
        int res = INT_MIN;
        int prefix_sum = 0, min_sum = 0;
        
        for (int n : arr) {
            prefix_sum += n;
            res = max(res, prefix_sum - min_sum);
            min_sum = min(min_sum, prefix_sum);
        }
        
        return res;
    }
};
