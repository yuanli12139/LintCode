/*
601. Flatten 2D Vector

Implement an iterator to flatten a 2d vector.

Example
Example 1:

Input:[[1,2],[3],[4,5,6]]
Output:[1,2,3,4,5,6]

Example 2:

Input:[[7,9],[5]]
Output:[7,9,5]


Author: Yuan Li
Date: 2/28/2019 
Difficulty: Medium
*/

class Vector2D {
  public:
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        begin_ = vec2d.begin();
        end_ = vec2d.end();
        pos_ = 0;
    }

    int next() {
        // Write your code here
        hasNext();
        return (*begin_)[pos_++];
    }

    bool hasNext() {
        // Write your code here
        while (begin_ != end_ && pos_ >= (*begin_).size()) {
            ++begin_;
            pos_ = 0;
        }
        return begin_ != end_;
    }
    
  private:
    vector<vector<int>>::iterator begin_, end_;
    int pos_;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
 
