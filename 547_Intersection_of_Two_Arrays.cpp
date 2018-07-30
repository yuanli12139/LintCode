/*
547. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.

Each element in the result must be unique.
The result can be in any order.

Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Challenge
Can you implement it in three different algorithms?


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Easy
*/

// hash map - O(n + m)
class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        vector<int> res;
        
        if (nums1.empty() || nums2.empty()) {
            return res;
        }
        
        unordered_map<int, bool> num2visited;
        for (int n1 : nums1) {
            num2visited[n1] = true;
        }
        
        for (int n2 : nums2) {
            if (num2visited.count(n2) && num2visited[n2]) {
                res.push_back(n2);
                num2visited[n2] = false;
            }
        }
        
        return res;
    }
};
