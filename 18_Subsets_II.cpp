/*
18. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Each element in a subset must be in non-descending order.
The ordering between two subsets is free.
The solution set must not contain duplicate subsets.

Example
Input: [1,2,2]
Output:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Challenge
Can you do it in both recursively and iteratively?


Author: Yuan Li
Date: 7/14/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> subset;
        
        if (nums.size() == 0) {
            res.push_back(subset);
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        dfs(subset, nums, 0, res);
        
        return res;
    }

    void dfs(vector<int> subset, vector<int> &nums, int startIdx, vector<vector<int>> &res) {
        res.push_back(subset);
        
        for (int i = startIdx; i < nums.size(); ++i) {
            if (i != startIdx && nums[i] == nums[i-1]) 
                continue;
                
            subset.push_back(nums[i]);
            dfs(subset, nums, i + 1, res);
            subset.pop_back();
        }
    }
};
