/*
548. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Challenge
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


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
        if (nums1.empty() || nums2.empty()) {
            return {};
        }
        
        if (nums1.size() < nums2.size()) {
            return helper(nums1, nums2);
        }
        
        return helper(nums2, nums1);
    }
    
    inline vector<int> helper(const vector<int> &smaller, const vector<int> &larger) {
        vector<int> res;
        
        unordered_map<int, int> num2cnt;
        for (int n1 : smaller) {
            if (!num2cnt.count(n1)) {
                num2cnt[n1] = 1;
            } else {
                num2cnt[n1]++;
            }
        }
        
        for (int n2 : larger) {
            if (num2cnt.count(n2) && num2cnt[n2] > 0) {
                res.push_back(n2);
                num2cnt[n2]--;
            }
        }
        
        return res;
    }
};


// sort & merge (two pointers) - O(nlong(n) + O(mlog(m)))
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
            
            res.push_back(nums1[i++]);
            j++;
        }
        
        return res;
    }
};
