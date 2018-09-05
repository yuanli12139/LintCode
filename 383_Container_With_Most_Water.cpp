/*
383. Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Example
Given [1,3,2], the max area of the container is 2.

Notice
You may not slant the container.


Author: Yuan Li
Date: 9/5/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int max_area = 0;
        
        int left = 0, right = heights.size() - 1;
        while (left < right) {
            if (heights[left] < heights[right]) {
                max_area = max(max_area, (right - left) * heights[left]);
                ++left;
            } else {
                max_area = max(max_area, (right - left) * heights[right]);
                --right;
            }
        }
        
        return max_area;
    }
};
