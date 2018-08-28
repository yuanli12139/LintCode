/*
1001. Asteroid Collision
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example
Input:
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation:
The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Input:
asteroids = [10, 2, -5]
Output: [10]
Explanation:
The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Notice
The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000]..


Author: Yuan Li
Date: 8/27/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param asteroids: a list of integers
     * @return: return a list of integers
     */
    vector<int> asteroidCollision(vector<int> &asteroids) {
        // write your code here
        vector<int> stk;
        for (int asteroid : asteroids) {
            if (stk.empty() || (stk.back() < 0 && asteroid > 0) || (stk.back() * asteroid > 0)) {
                stk.push_back(asteroid);
                continue;
            }
            
            int top = stk.back();
            while (!stk.empty() && stk.back() > 0 && asteroid < 0) {
                top = stk.back();
                stk.pop_back();
                
                if (top == -asteroid) {
                    break;
                }
                
                if (abs(top) > abs(asteroid)) {
                    stk.push_back(top);
                    break;
                }
            }
            
            if (abs(top) < abs(asteroid)) {
                stk.push_back(asteroid);
            }
        }
        
        return stk;
    }
};
