/*
131. The Skyline Problem
Given N buildings in a x-axis，each building is a rectangle and can be represented by a triple (start, end, height)，where start is the start position on x-axis, end is the end position on x-axis and height is the height of the building. Buildings may overlap if you see them from far away，find the outline of them。

An outline can be represented by a triple, (start, end, height), where start is the start position on x-axis of the outline, end is the end position on x-axis and height is the height of the outline.

Picture
https://lintcode-media.s3.amazonaws.com/problem/jiuzhang3.jpg

Example
Given 3 buildings：

[
  [1, 3, 3],
  [2, 4, 4],
  [5, 6, 1]
]
The outlines are：

[
  [1, 2, 3],
  [2, 4, 4],
  [5, 6, 1]
]

Notice
Please merge the adjacent outlines if they have the same height and make sure different outlines cant overlap on x-axis.

Reference
http://zxi.mytechroad.com/blog/tree/leetcode-218-the-skyline-problem/
https://briangordon.github.io/2014/08/the-skyline-problem.html


Author: Yuan Li
Date: 11/23/2018 
Difficulty: Super
*/

class Solution {
  public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
        // write your code here
        typedef pair<int, int> Event; // position, height
        vector<Event> events;
        
        heights_.clear();
        
        for (const auto &b : buildings) {
            events.emplace_back(b[0], b[2]);
            events.emplace_back(b[1], -b[2]);
        }
        
        sort(events.begin(), events.end(), [](const Event &lhs, const Event &rhs) {
           if (lhs.first == rhs.first) {
               return lhs.second > rhs.second;
           } 
           return lhs.first < rhs.first;
        });
        
        vector<vector<int>> res;
        for (const auto &e : events) {
            int x = e.first;
            int h = abs(e.second);
            
            if (e.second > 0) { // entering
                if (h > maxHeight()) {
                    merge(x, h, res);
                }
                heights_.insert(h);
            } else {
                heights_.erase(heights_.equal_range(h).first);
                if (h > maxHeight()) {
                    merge(x, maxHeight(), res);
                }
            }
        }
        
        return res;
    }
    
  private:
    multiset<int> heights_;
    int last_height_ = 0;
    
  private:
    int maxHeight() const {
        return heights_.empty() ? 0 : *heights_.rbegin();
    }
    
    void merge(int position, int height, vector<vector<int>> &intervals) {
        if (last_height_ > 0) {
            intervals.back()[1] = position;
        }
        
        if (height > 0) {
            intervals.push_back({position, position, height});
        }
        
        last_height_ = height;
    }
};

