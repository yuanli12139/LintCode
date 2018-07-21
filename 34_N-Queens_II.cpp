/*
34. N-Queens II
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Example
For n=4, there are 2 distinct solutions.


Author: Yuan Li
Date: 7/21/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        int num_sols = 0;
        vector<int> cols;
        vector<bool> visited(n, false);
        vector<bool> visited_sub(2*n, false);
        vector<bool> visited_sum(2*n, false);
        
        dfs(n, cols, visited, visited_sub, visited_sum, num_sols);
        return num_sols;
    }
    
    void dfs(int n, vector<int> cols, vector<bool> visited, 
            vector<bool> visited_sub, vector<bool> visited_sum, 
            int &num_sols) {
        if (n <= 0) {
            return;
        }
        
        if (cols.size() == n) {
            num_sols++;
            return;
        }
        
        for (int c = 0; c < n; ++c) {
            int new_r = cols.size();
            if (visited[c] || visited_sub[new_r-c+n] || visited_sum[new_r+c]) {
                continue;
            }
            
            cols.push_back(c);
            visited[c] = true;
            visited_sub[new_r-c+n] = true;
            visited_sum[new_r+c] = true;
            
            dfs(n, cols, visited, visited_sub, visited_sum, num_sols);
            
            cols.pop_back();
            visited[c] = false;
            visited_sub[new_r-c+n] = false;
            visited_sum[new_r+c] = false;
        }
    }
};
