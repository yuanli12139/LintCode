/*
124. Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Clarification
Your algorithm should run in O(n) complexity.


Author: Yuan Li
Date: 10/9/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        for (int n : num) {
            num_set_.insert(n);
        }
        
        int res = 0;
        for (int n : num) {
            if (num_set_.count(n)) {
                num_set_.erase(n);
                
                int l = n - 1;
                while (num_set_.count(l)) {
                    num_set_.erase(l--);
                }
                
                int r = n + 1;
                while (num_set_.count(r)) {
                    num_set_.erase(r++);
                }
                
                res = max(res, r - l - 1);
            }
        }
        
        return res;
    }
    
  private:
    unordered_set<int> num_set_;
};

