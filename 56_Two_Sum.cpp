/*
56. Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.

Example
numbers=[2, 7, 11, 15], target=9

return [0, 1]

Challenge
Either of the following solutions are acceptable:

O(n) Space, O(nlogn) Time
O(n) Space, O(n) Time

Notice
You may assume that each input would have exactly one solution


Author: Yuan Li
Date: 8/11/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        vector<int> res;
        
        vector<pair<int, int>> num_idx;
        for (int i = 0; i < numbers.size(); ++i) {
            num_idx.push_back(make_pair(numbers[i], i));
        }
        
        sort(num_idx.begin(), num_idx.end(), 
            [](const auto &a, const auto &b) -> bool {
                return a.first < b.first;
            });
            
        int i = 0, j = num_idx.size() - 1;
        while (i < j) {
            pair<int, int> left = num_idx[i], right = num_idx[j];
            
            if (left.first + right.first == target) {
                res = {min(left.second, right.second), max(left.second, right.second)};
                break;
            }
            
            if (left.first + right.first < target) {
                ++i;
            } else {
                --j;
            }
        }
        
        return res;
    }
};
