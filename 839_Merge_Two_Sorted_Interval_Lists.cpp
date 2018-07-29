/*
839. Merge Two Sorted Interval Lists
Merge two sorted (ascending) lists of interval and return it as a new sorted list. The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.

The intervals in the given list do not overlap.
The intervals in different lists may overlap.

Example
Given list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)], return [(1,4),(5,6)].


Author: Yuan Li
Date: 7/29/2018 
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

// O(n + m)
class Solution {
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        // write your code here
        vector<Interval> res;
        
        // if (list1.empty() && list2.empty()) {
        //     return res;
        // }
        
        if (list1.empty()) {
            return list2; // can be empty
        }
        
        if (list2.empty()) {
            return list1; // can be empty
        }
        
        int i = 0, j = 0;
        Interval buffer;
        
        while (i < list1.size() && j < list2.size()) {
            if (list1[i].start < list2[j].start) {
                buffer = list1[i++];
            } else {
                buffer = list2[j++];
            }
            
            merge(res, buffer);
        }
        
        while (i < list1.size()) {
            merge(res, list1[i++]);
        }
        
        while (j < list2.size()) {
            merge(res, list2[j++]);
        }
        
        return res;
    }
    
    void merge(vector<Interval> &res, const Interval &intv) {
        if (res.empty() || res.back().end < intv.start) {
            res.push_back(intv);
        } else {
            res.back().end = max(res.back().end, intv.end);
        }
    }
};
