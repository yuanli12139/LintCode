/*
1077. Falling Squares
On an infinite number line (x-axis), we drop given squares in the order they are given.

The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength positions[i][1].

The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next.

The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely.

Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, after dropping squares represented by positions[0], positions[1], ..., positions[i].

Example
Input: [[1, 2], [2, 3], [6, 1]]
Output: [2, 5, 5]
Explanation:

After the first drop of positions[0] = [1, 2]:
_aa
_aa
-------
The maximum height of any square is 2.


After the second drop of positions[1] = [2, 3]:
__aaa
__aaa
__aaa
_aa__
_aa__
--------------
The maximum height of any square is 5.  
The larger square stays on top of the smaller square despite where its center
of gravity is, because squares are infinitely sticky on their bottom edge.


After the third drop of positions[1] = [6, 1]:
__aaa
__aaa
__aaa
_aa
_aa___a
--------------
The maximum height of any square is still 5.

Thus, we return an answer of [2, 5, 5].
Input: [[100, 100], [200, 100]]
Output: [100, 100]
Explanation: Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surfaces.
Notice
1 <= positions.length <= 1000.
1 <= positions[i][0] <= 10^8.
1 <= positions[i][1] <= 10^6.

Reference
https://zxi.mytechroad.com/blog/geometry/leetcode-699-falling-squares/


Author: Yuan Li
Date: 9/2/2018 
Difficulty: Hard
*/

// brute force - O(n^2)
class Solution {
  public:
    /**
     * @param positions: a list of (left, side_length)
     * @return: return a list of integer
     */
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        // write your code here
        vector<int> res;
        
        vector<Interval> intervals;
        int max_height = 0;
        for (auto &pos : positions) {
            int start = pos[0], end = start + pos[1];
            int base_height = 0;
            
            for (auto &intv : intervals) {
                if (intv.end <= start || intv.start >= end) {
                    continue;
                }
                
                base_height = max(base_height, intv.height);
            }
            
            int new_height = base_height + pos[1];
            intervals.push_back(Interval(start, end, new_height));
            max_height = max(max_height, new_height);
            
            res.push_back(max_height);
        }
        
        return res;
    }

  private:
    struct Interval {
        Interval(int start, int end, int height) 
            : start(start), end(end), height(height) {}
        
        int start, end, height; 
    };
};


// map - O(n * log(n)) or worst: O(n^2)?
class Solution {
  public:
    /**
     * @param positions: a list of (left, side_length)
     * @return: return a list of integer
     */
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        // write your code here
        vector<int> res;
        
        int max_height = 0;
        for (auto &pos : positions) {
            int start = pos[0], end = start + pos[1];
            int base_height = 0;
            
            // find intersection
            auto it = intv_h_.upper_bound({start, end}); // O(log(n))
            auto tmp_it = it;
            if (tmp_it != intv_h_.begin() && (--tmp_it)->first.second > start) {
                it = tmp_it; 
            }
        
            vector<tuple<int, int, int>> ranges; // new ranges ({start, end, height}) after removing overlaps
            while (it != intv_h_.end() && it->first.first < end) {
                int it_start = it->first.first;
                int it_end = it->first.second;
                int it_height = it->second; 
                
                if (it_start < start) { // left overlapped
                    ranges.emplace_back(it_start, start, it_height);
                }
                
                if (it_end > end) { // right overlapped
                    ranges.emplace_back(end, it_end, it_height);
                }
                
                base_height = max(base_height, it_height);
                it = intv_h_.erase(it); // erase it, making it become its next - O(1)
            }

            // add new / adjusted intervals
            int new_height = base_height + pos[1];
            intv_h_[{start, end}] = new_height;  
            for (auto &range : ranges) {
                intv_h_[{get<0>(range), get<1>(range)}] = get<2>(range);
            }
            
            max_height = max(max_height, new_height);
            res.push_back(max_height);
        }

        return res;
    }

  private:
    map<pair<int, int>, int> intv_h_; // {{start, end}, height}, sorted in ascending order by start
};
