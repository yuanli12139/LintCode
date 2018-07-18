/*
15. Permutations
Given a list of numbers, return all possible permutations.

You can assume that there is no duplicate numbers in the list.

Example
For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

Challenge
Do it without recursion.

Author: Yuan Li
Date: 7/17/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: a list of permutations
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> visited(nums.size(), false);
        
        dfs(nums, visited, perm, res);
        
        return res; 
    }
    
    void dfs(vector<int> &nums, vector<bool> visited, vector<int> perm,
            vector<vector<int>> &res) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i])
                continue;
              
            // [] -> [1]  
            perm.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, perm, res);
            // [1] -> []
            perm.pop_back();
            visited[i] = false;
        }
    }
};
