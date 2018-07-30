/*
486. Merge K Sorted Arrays
Given k sorted integer arrays, merge them into one sorted array.

Example
Given 3 sorted arrays:

[
  [1, 3, 5, 7],
  [2, 4, 6],
  [0, 8, 9, 10, 11]
]
return [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].

Challenge
Do it in O(N log k).

N is the total number of integers.
k is the number of arrays.


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        vector<int> res;
        
        auto comp = [](const auto& lhs, const auto& rhs) -> bool {
            return lhs.first > rhs.first;    
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> pq(comp);
        
        for (int i = 0; i < arrays.size(); ++i) {
            if (!arrays[i].empty()) {
                pair<int, pair<int, int>> head(arrays[i][0], pair<int, int>(i, 0));
                pq.push(head);
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            
            int next_i = pq.top().second.first;
            int next_j = pq.top().second.second + 1;
            if (next_j < arrays[next_i].size()) {
                pair<int, pair<int, int>> next(arrays[next_i][next_j], pair<int, int>(next_i, next_j));
                pq.push(next);
            }

            pq.pop();
        }
        
        return res;
    }
};
