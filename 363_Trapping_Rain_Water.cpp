/*
363. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Picture
https://lintcode-media.s3.amazonaws.com/problem/rainwatertrap.png

Example
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Challenge
O(n) time and O(1) memory

O(n) time and O(n) memory is also acceptable.


Author: Yuan Li
Date: 9/6/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        if (heights.size() < 2) {
            return 0;
        }
        
        int water = 0;
        int left = 0, right = heights.size() - 1;
        int left_h = heights[left], right_h = heights[right];
        
        while (left < right) {
            if (heights[left] < heights[right]) {
                ++left;
                if (heights[left] < left_h) {
                    water += left_h - heights[left];
                } else {
                    left_h = heights[left];
                }
                
            } else {
                --right;
                if (heights[right] < right_h) {
                    water += right_h - heights[right];
                } else {
                    right_h = heights[right];
                }
            }
        }
        
        return water;
    }
};
