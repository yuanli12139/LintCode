/*
135. Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

Example
Given candidate set [2,3,6,7] and target 7, a solution set is:

[7]
[2, 2, 3]


Author: Yuan Li
Date: 7/14/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> comb;
        
        if (candidates.size() == 0) 
            return res;
            
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, target, comb, 0, res);
        
        return res;
    }
    
    void dfs(vector<int> &candidates, int remainTarget, vector<int> comb, 
            int startIdx, vector<vector<int>> &res) {
        if (remainTarget < 0)
            return;
        
        if (remainTarget == 0) {
            res.push_back(comb);
        }
        
        for (int i = startIdx; i < candidates.size(); ++i) {
            // remove duplicates
            if (i != startIdx && candidates[i] == candidates[i-1])
                continue;
                
            comb.push_back(candidates[i]);
            // passing in i + 1 avoids repeated choosing        
            dfs(candidates, remainTarget - candidates[i], comb, i, res);
            comb.pop_back();
        }
    }
};
