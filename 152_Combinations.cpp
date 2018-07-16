/*
152. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You don't need to care the order of combinations, but you should make sure the numbers in a combination are sorted.

Example
Given n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4]
]


Author: Yuan Li
Date: 7/15/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        // write your code here
        vector<vector<int>> res;
        vector<int> comb;
        
        dfs(n, k, comb, 0, res);
        return res;
    }
    
    void dfs(int n, int remainK, vector<int> comb, int idx, 
            vector<vector<int>> &res) {
        if (remainK == 0) {
            res.push_back(comb);
            return;
        }
        
        if (idx == n || n - idx < remainK)
            return;
        
        int num = idx + 1;
        
        // pick num
        comb.push_back(num);
        dfs(n, remainK - 1, comb, idx + 1, res);
        
        // do not pick num
        comb.pop_back();
        dfs(n, remainK, comb, idx + 1, res);
    }
};
