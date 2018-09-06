/*
641. Missing Ranges
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example
Given nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99
return ["2", "4->49", "51->74", "76->99"].


Author: Yuan Li
Date: 9/5/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here
        vector<string> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i]; 
            
            // handle duplicates
            if (i > 0 && num == nums[i-1]) {
                continue;
            }
            
            if (lower < num) {
                if (lower + 1 < num) {
                    res.push_back(to_string(lower) + "->" + to_string(num - 1));
                } else { // lower + 1 == num
                    res.push_back(to_string(lower));
                }
            }
            
            lower = num + 1;
        }
        
        if (lower > upper) { 
            return res;
        }
        
        // handle int overflow
        // if nums is not empty, meaning lower can't initially be INT_MIN
        if (!nums.empty() && lower == INT_MIN) { 
            return res;
        }
        
        if (lower < upper) {
            res.push_back(to_string(lower) + "->" + to_string(upper));
        } else { // lower == upper
            res.push_back(to_string(upper));
        }
        
        return res;
    }
};
