/*
153. Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

Example
Given candidate set [10,1,6,7,2,1,5] and target 8,

A solution set is:

[
  [1,7],
  [1,2,5],
  [2,6],
  [1,1,6]
]


Author: Yuan Li
Date: 7/14/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> comb;
        
        if (num.size() == 0)
            return res;
        
        sort(num.begin(), num.end());
        
        dfs(num, target, comb, 0, res);
        
        return res;
    }
    
    void dfs(vector<int> &num, int remainTarget, vector<int> comb, 
            int startIdx, vector<vector<int>> &res) {
        if (remainTarget < 0) 
            return;
            
        if (remainTarget == 0) {
            res.push_back(comb);
        }
        
        for (int i = startIdx; i < num.size(); ++i) {
            if (i != 0 && num[i] == num[i-1])
                continue;
                
            comb.push_back(num[i]);
            dfs(num, remainTarget - num[i], comb, i + 1, res);
            comb.pop_back();
        }
    }
};
