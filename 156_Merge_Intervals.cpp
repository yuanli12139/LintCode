/*
156. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

Example
Given intervals => merged intervals:

[                     [
  (1, 3),               (1, 6),
  (2, 6),      =>       (8, 10),
  (8, 10),              (15, 18)
  (15, 18)            ]
]

Challenge
O(n log n) time and O(1) extra space.


Author: Yuan Li
Date: 10/29/2018 
Difficulty: Easy
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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(), intervals.end(), 
            [](const Interval &lhs, const Interval &rhs) {
                return lhs.start < rhs.start;    
            });
            
        vector<Interval> res;
        for (auto intv : intervals) {
            if (res.empty() || res.back().end < intv.start) {
                res.push_back(intv);
            } else {
                res.back().end = max(res.back().end, intv.end);
            }
        }
        
        return res;
    }
};

