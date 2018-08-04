/*
521. Remove Duplicate Numbers in Array
Given an array of integers, remove the duplicate numbers in it.

You should:

Do it in place in the array.
Move the unique numbers to the front of the array.
Return the total number of the unique numbers.

You don't need to keep the original order of the integers.

Example
Given nums = [1,3,1,4,4,2], you should:

Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
Return the number of unique integers in nums => 4.
Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.

Challenge
Do it in O(n) time complexity.
Do it in O(nlogn) time without extra space.


Author: Yuan Li
Date: 8/4/2018 
Difficulty: Easy
*/

class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }
        
        unordered_set<int> unique_nums;
        int i = 0, j = 0;
        
        while (j < nums.size()) {
            if (!unique_nums.count(nums[i])) {
                unique_nums.insert(nums[i]);
                i++;
                j++;
                continue;
            }
            
            if (unique_nums.count(nums[j])) {
                j++;
                continue;
            }
            
            swap(nums, i, j);
        }
        
        return i;
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
