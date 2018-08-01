/*
840. Range Sum Query - Mutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

1.The array is only modifiable by the update function.
2.You may assume the number of calls to update and sumRange function is distributed evenly.

Example
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8


Author: Yuan Li
Date: 7/31/2018 
Difficulty: Medium
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        arr.resize(nums.size());
        bit.resize(nums.size() + 1);
        
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int delta = val - arr[i];
        arr[i] = val;
        
        for (int idx = i + 1; idx <= arr.size(); idx += lowBit(idx)) {
            bit[idx] += delta;
        }
    }
    
    int sumRange(int i, int j) {
        return getPrefixSum(j) - getPrefixSum(i-1); 
    }
    
    int getPrefixSum(int i) {
        int prefixSum = 0;
        for (int idx = i + 1; idx > 0; idx -= lowBit(idx)) {
            prefixSum += bit[idx];
        }
        
        return prefixSum;
    }
    
    int lowBit(int x) {
        return x & (-x);
    }
    
private:
    vector<int> arr;
    vector<int> bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
 