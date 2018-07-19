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


/* Date: 7/18/2018 */
// non-recursion
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: a list of permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        bool next = true;
        while(next) { 
            res.push_back(nums);
            next = nextPermutation(nums);
        }
        
        return res; 
    }
    
    bool nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1)
            return false;
            
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        
        if (i > 0) {
            int j = nums.size() - 1;
            while (i < j && nums[i-1] >= nums[j]) {
                j--;
            }
            
            swap(nums, i-1, j);
            reverse(nums.begin() + i, nums.end());
            
            return true;
        }
        
        return false;
    }
    
    void swap(vector<int> &nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
};
