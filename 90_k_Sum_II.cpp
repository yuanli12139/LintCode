/*
90. k Sum II
Given n unique integers, number k (1<=k<=n) and target.

Find all possible k integers where their sum is target.

Example
Given [1,2,3,4], k = 2, target = 5. Return:

[
  [1,4],
  [2,3]
]


Author: Yuan Li
Date: 7/14/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> comb;
        
        if (A.size() == 0) 
            return res;
            
        sort(A.begin(), A.end());
        
        dfs(A, k, target, comb, 0, res);
        
        return res;
    }
    
    void dfs(vector<int> &A, int remainK, int remainTarget, 
            vector<int> comb, int startIdx, vector<vector<int>> &res) {
        if (remainK < 0 || remainTarget < 0) 
            return;
            
        if (remainK == 0 && remainTarget == 0) {
            res.push_back(comb);
        }
        
        for (int i = startIdx; i < A.size(); ++i) {
            comb.push_back(A[i]);
            dfs(A, remainK - 1, remainTarget - A[i], comb, i + 1, res);
            comb.pop_back();
        }
    }
};
