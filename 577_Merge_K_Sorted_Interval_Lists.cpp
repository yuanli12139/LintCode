/*
577. Merge K Sorted Interval Lists
Merge K sorted interval lists into one sorted interval list. You need to merge overlapping intervals too.

Example
Given

[
  [(1,3),(4,7),(6,8)],
  [(1,2),(9,10)]
]
Return

[(1,3),(4,8),(9,10)]


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Medium
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        // write your code here
        vector<Interval> res;
        
        auto comp = [](const auto &lhs, const auto &rhs) -> bool {
            return lhs.first->start > rhs.first->start;    
        };
        priority_queue<pair<Interval*, pair<int, int>>, 
                        vector<pair<Interval*, pair<int, int>>>, 
                        decltype(comp)> pq(comp); 
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (!intervals[i].empty()) {
                Interval* head_intv = &intervals[i][0];
                pair<Interval*, pair<int, int>> head(head_intv, pair<int, int>(i, 0));
                pq.push(head);
            }
        }
        
        while (!pq.empty()) {
            if (res.empty() || res.back().end < pq.top().first->start) {
                res.push_back(*(pq.top().first));
            } else {
                res.back().end = max(res.back().end, pq.top().first->end);
            }
            
            int next_i = pq.top().second.first;
            int next_j = pq.top().second.second + 1;
            
            if (next_j < intervals[next_i].size()) {
                Interval* next_intv = &intervals[next_i][next_j];
                pair<Interval*, pair<int, int>> next(next_intv, pair<int, int>(next_i, next_j));
                pq.push(next);
            }
            
            pq.pop();
        }
        
        return res;
    }
};
