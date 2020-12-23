/*
460. Find K Closest Elements
Given a target number, a non-negative integer target and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

The value k is a non-negative integer and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 10^4
Absolute value of elements in the array and x will not exceed 10^4

Example
Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].

Challenge
O(logn + k) time complexity.


Author: Yuan Li
Date: 6/26/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        vector<int> res;
        
        if (k == 0) 
            return res;
        
        int closestId = findClosest(A, target);
        res.push_back(A[closestId]);
        
        int left = closestId - 1, right = closestId + 1;
        for (int i = k - 1; i > 0; i--) {
            if (isLeftCloser(A, target, left, right)) {
                res.push_back(A[left]);
                left--;
            } else {
                res.push_back(A[right]);
                right++;
            }
        }
        
        return res;
    }
    
    int findClosest(vector<int> &A, int target) {
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (A[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (target - A[start] <= A[end] - target) {
            return start;
        }
        
        return end;
    }
    
    bool isLeftCloser(vector<int> &A, int target, int left, int right) {
        if (left < 0) 
            return false;
        
        if (right > A.size() - 1) 
            return true;
            
        return target - A[left] <= A[right] - target;
    }
};
