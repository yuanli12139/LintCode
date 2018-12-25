/*
434. Number of Islands II
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.

Example
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].

return [1,1,2,2].

Notice
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.


Author: Yuan Li
Date: 12/24/2018 
Difficulty: Medium
*/

#include <boost/functional/hash.hpp>

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
  public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        vector<int> res;    
        
        for (Point op : operators) {
            if (islands_.count({op.x, op.y})) {
                res.push_back(count_);
                continue;
            }
            
            islands_.insert({op.x, op.y});
            father_[{op.x, op.y}] = {op.x, op.y};
            ++count_;
            
            for (int i = 0; i < 4; ++i) {
                int nx = op.x + dx_[i];
                int ny = op.y + dy_[i];
            
                if (islands_.count({nx, ny})) {
                    merge(op, Point(nx, ny));
                }
            }
            
            res.push_back(count_);
        }
        
        return res;
    }
    
  private:
    int count_ = 0;
    unordered_map<pair<int, int>, pair<int, int>, boost::hash<pair<int, int>>> father_;
    unordered_set<pair<int, int>, boost::hash<pair<int, int>>> islands_;
    
    vector<int> dx_ = {-1, 1, 0, 0};
    vector<int> dy_ = {0, 0, -1, 1};
    
  private:
    void merge(Point a, Point b) {
        Point rt_a = find(a);
        Point rt_b = find(b);
        if ((rt_a.x != rt_b.x) || (rt_a.y != rt_b.y)) {
            father_[{rt_a.x, rt_a.y}] = {rt_b.x, rt_b.y};
            --count_;
        }
    }
    
    Point find(Point pt) {
        pair<int, int> pt_pair = {pt.x, pt.y};
        
        vector<pair<int, int>> path;
        while (father_[pt_pair] != pt_pair) {
            path.push_back(pt_pair);
            pt_pair = father_[pt_pair]; 
        }
        
        for (auto p : path) {
            father_[p] = pt_pair;
        }
        
        return Point(pt_pair.first, pt_pair.second);
    }
};

