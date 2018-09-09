/*
931. Median of K Sorted Arrays
There are k sorted arrays nums. Find the median of the given k sorted arrays.

The length of the given arrays may not equal to each other.
The elements of the given arrays are all positive number.
Return 0 if there are no elements in the array.

Example
Given nums = [[1],[2],[3]], return 2.00.


Author: Yuan Li
Date: 7/30/2018 
Difficulty: Medium
*/

// binary search - O(log(range) * klog(n)) = O(32klog(n))
// range: range between the min and the max integer, i.e. INT_MAX - 1 + 1
class Solution {
  public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(vector<vector<int>> &nums) {
        // write your code here
        int n = 0;
        for (auto &arr : nums) {
            if (!arr.empty()) {
                min_val_ = min(min_val_, arr[0]);
                max_val_ = max(max_val_, arr.back());
            }
            
            n += arr.size();
        }
        
        if (n == 0) {
            return 0;
        }
        
        if (n % 2 == 0) {
            return (findKth(nums, n / 2) + findKth(nums, n / 2 + 1)) / 2.;
        }
        
        return findKth(nums, n / 2 + 1);
    }
    
  private:
    int min_val_ = 1;
    int max_val_ = INT_MAX;
    
  private:
    // binary search for the median value
    double findKth(const vector<vector<int>> &nums, int k) {
        int start = min_val_, end = max_val_;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (countLTE(nums, mid) < k) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        // find the first val
        if (countLTE(nums, start) == k) {
            return start;
        }
        
        return end;
    }
    
    int countLTE(const vector<vector<int>> &nums, int val) {
        int res = 0;
        for (auto &arr : nums) {
            res += countLTE(arr, val);
        }
        
        return res;
    }
    
    // binary search for the position, i.e. number of elements â‰¤ val
    int countLTE(const vector<int> &arr, int val) {
        if (arr.empty()) {
            return 0;
        }
        
        int start = 0, end = arr.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == val) {
                return mid + 1;
            }
            
            if (arr[mid] < val) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        // 2 3 4 5 6 <8>
        if (arr[end] <= val) {
            return end + 1; // end + 1 == arr.size()
            // return arr.size();
        }
        
        // 2 3 4 5 6 <3>
        if (arr[start] <= val) {
            return start + 1; // start + 1 == end;
            // return end;
        }
        
        // 2 3 4 5 6 <1>
        return 0; // start == 0
        // return start; 
    }
};
