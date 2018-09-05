/*
1238. Find All Duplicates in an Array
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

Reference
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/


Author: Yuan Li
Date: 9/5/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    vector<int> findDuplicates(vector<int> &nums) {
        // write your code here
        vector<int> res;
        
        for (int num : nums) {
            if (nums[abs(num)-1] < 0) {
                res.push_back(abs(num));
            } else {
                nums[abs(num)-1] = -nums[abs(num)-1];
            }
        }
        
        return res;
    }
};
