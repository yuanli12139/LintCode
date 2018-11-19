/*
391. Number of Airplanes in the Sky
Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?

Example
For interval list

[
  (1,10),
  (2,3),
  (5,8),
  (4,7)
]
Return 3

Notice
If landing and flying happens at the same time, we consider landing should happen at first.


Author: Yuan Li
Date: 11/18/2018 
Difficulty: Medium
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

class Solution {
  public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int, int>> endpoints;
        for (auto airplane : airplanes) {
            endpoints.push_back({airplane.start, 1});
            endpoints.push_back({airplane.end, -1});
        }
        
        sort(endpoints.begin(), endpoints.end(), 
            [](auto const &lhs, auto const &rhs) {
                if (lhs.first == rhs.first) {
                    return lhs.second < rhs.second; 
                } else {
                    return lhs.first < rhs.first;
                }
                return true;
            });
            
        int num_airplane = 0;
        int max_airplane = 0;
        for (auto endpoint : endpoints) {
            num_airplane += endpoint.second;
            max_airplane = max(max_airplane, num_airplane);
        }
        
        return max_airplane;
    }
};

