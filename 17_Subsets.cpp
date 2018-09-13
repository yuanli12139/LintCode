/*
17. Subsets
Given a set of distinct integers, return all possible subsets.

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

Example
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Challenge
Can you do it in both recursively and iteratively?

Notice
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.


Author: Yuan Li
Date: 7/14/2018 
Difficulty: Medium
*/

// tranditional recursion-based DFS
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
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
            // [] -> [1]
            subset.push_back(nums[i]);
            
            // find subsets starting with [1]
            dfs(subset, nums, i + 1, res);
            
            // backtracking: [1] -> []
            subset.pop_back();
        }
    }
};


// combination-based DFS
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
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
    
    void dfs(vector<int> subset, vector<int> &nums, int idx, vector<vector<int>> &res) {
        // selection complete, return
        if (idx == nums.size()) {
            res.push_back(subset);
            return;
        }
        
        // pick nums[idx]
        subset.push_back(nums[idx]);
        dfs(subset, nums, idx + 1, res);
        
        // not pick nums[idx]
        subset.pop_back();
        dfs(subset, nums, idx + 1, res);
    }
};


// BFS enumeration
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> subset;

        if (nums.size() == 0) {
            res.push_back(subset);
            return res;
        }
            
        sort(nums.begin(), nums.end());
        
        queue<vector<int>> subsetQueue;
        subsetQueue.push(subset);
        
        while (!subsetQueue.empty()) {
            size_t size = subsetQueue.size();
            for (int i = 0; i < size; ++i) {
                vector<int> curr_subset = subsetQueue.front();
                res.push_back(curr_subset);
                subsetQueue.pop();
                
                for (int j = 0; j < nums.size(); ++j) {
                    // set of distinct integers
                    if (curr_subset.size() == 0 || nums[j] > curr_subset.back()) {
                        vector<int> next_subset(curr_subset);
                        next_subset.push_back(nums[j]);
                        subsetQueue.push(next_subset);
                    }
                }
            }
        }
        
        return res;
    }
};


// binary representation
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // 1 << n is 2^n
        // each subset equals to an binary integer between 0 ... 2^n - 1
        // 0 -> 000 -> []
        // 1 -> 001 -> [1]
        // 2 -> 010 -> [2]
        // ...
        // 7 -> 111 -> [1,2,3]
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            
            res.push_back(subset);
        }
        
        return res;
    }
};
