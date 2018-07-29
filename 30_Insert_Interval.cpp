/*
30. Insert Interval
Given a non-overlapping interval list which is sorted by start point.

Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).

Example
Insert (2, 5) into [(1,2), (5,9)], we get [(1,9)].

Insert (3, 4) into [(1,2), (5,9)], we get [(1,2), (3,4), (5,9)].


Author: Yuan Li
Date: 7/28/2018 
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
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> res;
        
        int i = 0;
        while (i < intervals.size() && intervals[i].start < newInterval.start) {
            i++;
        }
        
        intervals.insert(intervals.begin() + i, newInterval);
        
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
