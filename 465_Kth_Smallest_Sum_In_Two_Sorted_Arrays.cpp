/*
465. Kth Smallest Sum In Two Sorted Arrays
Given two integer arrays sorted in ascending order and an integer k. Define sum = a + b, where a is an element from the first array and b is an element from the second one. Find the kth smallest sum out of all possible sums.

Example
Given [1, 7, 11] and [2, 4, 6].

For k = 3, return 7.

For k = 4, return 9.

For k = 8, return 15.

Challenge
Do it in either of the following time complexity:

O(k log min(n, m, k)). where n is the size of A, and m is the size of B.
O( (m + n) log maxValue). where maxValue is the max number in A and B.


Author: Yuan Li
Date: 10/7/2018 
Difficulty: Hard
*/

// O(k * log(min(n, m, k)))
#include <boost/functional/hash.hpp>

class Solution {
  public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        // write your code here
        auto comp = [&](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return A[lhs.first] + B[lhs.second] > A[rhs.first] + B[rhs.second];
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
                
                if (valid(make_pair(nr, nc), A, B)) {
                    pq.push(make_pair(nr, nc));
                    rm_.insert(make_pair(nr, nc));
                }
            }
        }
        
        return A[r] + B[c];
    }
    
  private:
    unordered_set<pair<int, int>, boost::hash<pair<int, int>>> rm_;
    vector<int> dr_ = {0, 1};
    vector<int> dc_ = {1, 0};
    
  private:
    bool valid(const pair<int, int> crd, const vector<int> &A, const vector<int> &B) {
        int r = crd.first, c = crd.second;
        
        return !rm_.count(crd) 
                && (rm_.count(make_pair(r - 1, c)) || r - 1 < 0) 
                && (rm_.count(make_pair(r, c - 1)) || c - 1 < 0) 
                && r < A.size() && c < B.size();
    }
};

