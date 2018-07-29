/*
65. Median of two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example
Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.

Given A=[1,2,3] and B=[4,5], the median is 3.

Challenge
The overall run time complexity should be O(log (m+n)).


Author: Yuan Li
Date: 7/28/2018 
Difficulty: Medium
*/

// binary search - O(log(range) * log(m) + log(n))
// range: range between the min and the max integer, i.e. max(max(A), max(B)) - min(min(A), min(B)) + 1
class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        int n = A.size() + B.size(); // n >= 1
        
        if (n % 2 == 0) {
            return (median(A, B, n / 2) + median(A, B, n / 2 + 1)) / 2.;
        }
        
        return median(A, B, n / 2 + 1);
    }
    
    int median(vector<int> &A, vector<int> &B, int k) {
        if (A.empty()) {
            return B[k-1];
        }
        
        if (B.empty()) {
            return A[k-1];
        }
        
        int start = min(A[0], B[0]);
        int end = max(A.back(), B.back());
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (countSmallerEqual(A, mid) + countSmallerEqual(B, mid) < k) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (countSmallerEqual(A, start) + countSmallerEqual(B, start) >= k) {
            return start;
        }
        
        return end;
    }
    
    int countSmallerEqual(vector<int> arr, int num) {
        int start = 0, end = arr.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= num) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        // all numbers in arr > num, start == 0
        if (arr[start] > num) {
            // return start;
            return 0;
        }
        
        // arr[start] <= num, start + 1 == end
        if (arr[end] > num) {
            return end;
        }
        
        // all numbers in arr < num, return the number of numbers in arr
        return arr.size();
    }
};
