/*
1062. Flood Fill
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

Notice
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param image: a 2-D array
     * @param sr: an integer
     * @param sc: an integer
     * @param newColor: an integer
     * @return: the modified image
     */
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        // Write your code here
        visited_.resize(image.size(), vector<bool>(image[0].size(), false));
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited_[sr][sc] = true;
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int next_r = curr.first + dr[i];
                int next_c = curr.second + dc[i];
                
                if (isValid(next_r, next_c, image) && image[next_r][next_c] == image[sr][sc]) {
                    image[next_r][next_c] = newColor;
                    q.push({next_r, next_c});
                    visited_[next_r][next_c] = true;
                }
            }
        }
        
        image[sr][sc] = newColor;
        
        return image;
    }
    
  private:
    // unordered_set<pair<int, int>> visited_; // unordered_set can't take pair as the key
    vector<vector<bool>> visited_;
    
  private:
    bool isValid(int r, int c, vector<vector<int>> &image) {
        return r >= 0 && r < image.size() && c >= 0 && c < image[0].size() && !visited_[r][c];
    }
};
