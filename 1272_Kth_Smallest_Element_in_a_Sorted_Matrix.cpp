/*
1272. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example
matrix = [
[ 1, 5, 9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,

return 13.

Challenge
If k << n^2, what's the best algorithm?
How about k ~ n^2?

Notice
You may assume k is always valid, 1 ≤ k ≤ n^2.


Author: Yuan Li
Date: 10/6/2018 
Difficulty: Medium
*/

// O(k * log(min(n, m)))
#include <boost/functional/hash.hpp>

class Solution {
  public:
    /**
     * @param matrix: List[List[int]]
     * @param k: a integer
     * @return: return a integer
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        auto comp = [&](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return matrix[lhs.first][lhs.second] > matrix[rhs.first][rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        int r, c;
        pq.push(make_pair(0, 0));
        rm_.insert(make_pair(0, 0));
        
        while (k-- > 0) {
            r = pq.top().first;
            c = pq.top().second;
            pq.pop();
            
            for (int i = 0; i < 2; ++i) {
                int nr = r + dr_[i];
                int nc = c + dc_[i];
                
                if (valid(make_pair(nr, nc), matrix)) {
                    pq.push(make_pair(nr, nc));
                    rm_.insert(make_pair(nr, nc));
                }
            }
        }
        
        return matrix[r][c];
    }
    
  private:
    unordered_set<pair<int, int>, boost::hash<pair<int, int>>> rm_;
    vector<int> dr_ = {0, 1};
    vector<int> dc_ = {1, 0};
    
  private:
    bool valid(const pair<int, int> crd, const vector<vector<int>> &matrix) {
        int r = crd.first, c = crd.second;
        
        return !rm_.count(crd) 
                && (rm_.count(make_pair(r - 1, c)) || r - 1 < 0) 
                && (rm_.count(make_pair(r, c - 1)) || c - 1 < 0) 
                && r < matrix.size() && c < matrix[0].size();
    }
};

