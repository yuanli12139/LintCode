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
Difficulty: Hard
*/

// binary search - O(log(range) * (log(m) + log(n)))
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
        
        if (countSmallerEqual(A, start) + countSmallerEqual(B, start) == k) {
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
        
        // all numbers in arr < num or arr[end] == num, return the number of numbers in arr
        return arr.size();
    }
};


// exclusion - O(log(m + n))
class Solution {
  public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    class PartialArr {
      public:
        PartialArr(const vector<int> &arr) {
            arr_ = arr;
            start_ = 0;
            end_ = arr.size() - 1;
        }
        
        int size() {
            return end_ - start_ + 1;
        }
        
        double getMedian() {
            return (getLowerMedian() + getUpperMedian()) / 2.;
        }
        
        int getLowerMedianIdx() {
            return (start_ + end_) / 2;
        }
        
        int getUpperMedianIdx() {
            return (start_ + end_ + 1) / 2;
        }
        
        int getLowerMedian() {
            return arr_[getLowerMedianIdx()];
        }
        
        int getUpperMedian() {
            return arr_[getUpperMedianIdx()];
        }
        
        int numRemoveLower(int idx) {
            return idx - start_ + 1;
        }
        
        int numRemoveUpper(int idx) {
            return end_ - idx + 1; 
        }
        
        void removeLower(int n) {
            start_ += n;
        }
        
        void removeUpper(int n) {
            end_ -= n;
        }
        
        bool empty() {
            return size() == 0;
        }
        
      private:
        vector<int> arr_;
        int start_, end_;
    };
    
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        PartialArr partialA(A);
        PartialArr partialB(B);
        
        return median(partialA, partialB);
    }
    
    double median(PartialArr &A, PartialArr &B) {
        while (!A.empty() && !B.empty()) {
            if (A.size() == 1 && B.size() == 1) {
                return (A.getMedian() + B.getMedian()) / 2.;
            }
            
            // locate lower median
            PartialArr* lowerMedianArr = &A;
            int lowerMedianIdx = A.getLowerMedianIdx();
            if (A.getLowerMedian() > B.getLowerMedian()) {
                lowerMedianArr = &B;
                lowerMedianIdx = B.getLowerMedianIdx();
            }
            
            // locate upper median
            PartialArr* upperMedianArr = &A;
            int upperMedianIdx = A.getUpperMedianIdx();
            if (A.getUpperMedian() < B.getUpperMedian()) {
                upperMedianArr = &B;
                upperMedianIdx = B.getUpperMedianIdx();
            }
            
            // early stop - two arrays have a same single median
            if (lowerMedianArr->getLowerMedian() == upperMedianArr->getUpperMedian()) {
                return lowerMedianArr->getLowerMedian();
            }
            
            // remove same number of small and large numbers
            int minRemove = min(lowerMedianArr->numRemoveLower(lowerMedianIdx), 
                                upperMedianArr->numRemoveUpper(upperMedianIdx));

            lowerMedianArr->removeLower(minRemove);
            upperMedianArr->removeUpper(minRemove);
        }

        if (A.empty()) {
            return B.getMedian();
        }
        
        return A.getMedian();
    }
};


// divide & conquer - O(log(m + n))
class Solution {
  public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        int n = A.size() + B.size();
        
        if (n % 2 == 0) {
            return (findKth(A, 0, B, 0, n / 2) + findKth(A, 0, B, 0, n / 2 + 1)) / 2.;
        }
        
        return findKth(A, 0, B, 0, n / 2 + 1);
    }
    
    int findKth(vector<int> &A, int start_A, vector<int> &B, int start_B, int k) {
        if (start_A >= A.size()) {
            return B[start_B + k - 1];
        }
        
        if (start_B >= B.size()) {
            return A[start_A + k - 1];
        }
        
        if (k == 1) {
            return min(A[start_A], B[start_B]);
        }
        
        // weed out k / 2 smaller numbers
        int A_halfKth = start_A + k / 2 - 1 < A.size() ? A[start_A + k / 2 - 1] : INT_MAX;
        int B_halfKth = start_B + k / 2 - 1 < B.size() ? B[start_B + k / 2 - 1] : INT_MAX;
        
        if (A_halfKth < B_halfKth) {
            return findKth(A, start_A + k / 2, B, start_B, k - k / 2);
        }

        return findKth(A, start_A, B, start_B + k / 2, k - k / 2);
    }
};
