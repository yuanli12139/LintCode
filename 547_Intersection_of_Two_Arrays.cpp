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
        
        if (nums1.size() < nums2.size()) {
            return helper(nums1, nums2);
        }
        
        return helper(nums2, nums1);
    }
    
    inline vector<int> helper(const vector<int> &smaller, const vector<int> &larger) {
        vector<int> res;
        
        unordered_map<int, bool> num2visited;
        for (int n1 : smaller) {
            num2visited[n1] = true;
        }
        
        for (int n2 : larger) {
            if (num2visited.count(n2) && num2visited[n2]) {
                res.push_back(n2);
                num2visited[n2] = false;
            }
        }
        
        return res;
    } 
};


// sort & merge - O(nlog(n) + mlog(m))
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
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
                continue;
            }
            
            if (nums1[i] > nums2[j]) {
                j++;
                continue;
            }
            
            // nums[i] == nums[j]
            if (res.empty() || res.back() != nums1[i]) {
                res.push_back(nums1[i]);
            }
            
            i++;
            j++;
        }
        
        return res;
    }
};

