/*
612. K Closest Points
Given some points and a point origin in two dimensional space, find k points out of the some points which are nearest to origin.
Return these points sorted by distance, if they are same with distance, sorted by x-axis, otherwise sorted by y-axis.

Example
Given points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
return [[1,1],[2,5],[4,4]]


Author: Yuan Li
Date: 7/26/2018 
Difficulty: Medium
*/

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
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        vector<Point> res;
        
        // max-heap
        auto comp = [&](const Point &a, const Point &b) -> bool {
            int dist_a = getDist(a, origin);
            int dist_b = getDist(b, origin);
                            
            if (dist_a == dist_b) {
                if (a.x == b.x) {
                    return a.y < b.y;
                }
                
                return a.x < b.x;
            }
            
            return dist_a < dist_b;
        };
        priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
        
        // knock out n - k farthest points
        for (auto &point : points) {
            if (pq.size() < k) {
                pq.push(point);
                continue;
            }
            
            if (comp(point, pq.top())) {
                pq.pop();
                pq.push(point);
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    // if int didn't pass, consider converting (a, b, return value) to long, long long, etc.
    inline int getDist(const Point &a, const Point &b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
};
