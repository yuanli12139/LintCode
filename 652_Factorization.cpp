/*
652. Factorization
A non-negative numbers can be regarded as product of its factors.
Write a function that takes an integer n and return all possible combinations of its factors.

Example
Given n = 8
return [[2,2,2],[2,4]]
// 8 = 2 x 2 x 2 = 2 x 4.

Given n = 1
return []

Given n = 12
return [[2,6],[2,2,3],[3,4]]

Notice
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combination.


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<vector<int>> res;
        if (n <= 1) {
            return res;
        }
        
        vector<int> factors;
        dfs(n, 2, factors, res);
        return res;
    }
    
  private:
    void dfs(int n, int start, vector<int> factors, vector<vector<int>> &res) {
        if (n == 1 && factors.size() > 1) { 
            res.push_back(factors);
            return;
        }
        
        for (int factor = start; factor <= sqrt(n); ++factor) {
            if (n % factor == 0) {
                factors.push_back(factor);
                dfs(n / factor, factor, factors, res);
                factors.pop_back();
            }
        }
        
        if (n >= start) {
            factors.push_back(n);
            dfs(1, n, factors, res);
            factors.pop_back();
        }
    }
};


// // time limit exceeded
// class Solution {
//   public:
//     /**
//      * @param n: An integer
//      * @return: a list of combination
//      */
//     vector<vector<int>> getFactors(int n) {
//         // write your code here
//         vector<vector<int>> res;
//         if (n <= 1) {
//             return res;
//         }
        
//         vector<int> factors;
//         dfs(n, factors, 1, res);
//         return res;
//     }
    
//   private:
//     void dfs(int n, vector<int> factors, int prod, vector<vector<int>> &res) {
//         if (prod == n) {
//             res.push_back(factors);
//             return;
//         }
        
//         int factor = factors.empty() ? 2 : factors.back();
//         for (; factor <= min(n / prod, n / 2); ++factor) {
//             if ((n / prod) % factor == 0) {
//                 factors.push_back(factor);
//                 dfs(n, factors, prod * factor, res);
//                 factors.pop_back();
//             }
//         }
//     }
// };
