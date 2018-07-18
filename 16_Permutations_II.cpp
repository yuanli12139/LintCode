/*
16. Permutations II
Given a list of numbers with duplicate number in it. Find all unique permutations.

Example
For numbers [1,2,2] the unique permutations are:

[
  [1,2,2],
  [2,1,2],
  [2,2,1]
]

Challenge
Using recursion to do it is acceptable. If you can do it without recursion, that would be great!


Author: Yuan Li
Date: 7/17/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> visited(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        dfs(nums, perm, visited, res);
        
        return res;
    }
    
    void dfs(vector<int> &nums, vector<int> perm, vector<bool> visited, 
            vector<vector<int>> &res) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i])
                continue;
                
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
                
            perm.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, perm, visited, res);
            perm.pop_back();
            visited[i] = false;
        }
    } 
};
