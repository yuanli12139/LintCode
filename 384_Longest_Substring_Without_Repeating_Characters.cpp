/*
384. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Example
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

Challenge
O(n) time


Author: Yuan Li
Date: 9/19/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        int res = 0;
        if (s.empty()) {
            return res;
        }
        
        int n = s.size();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && !unique_chs_.count(s[j])) {
                unique_chs_.insert(s[j++]);
            }
            
            // if j == n, s[j] doesn't exist hence is not in unique_chs_
            res = max(res, j - i);    
            unique_chs_.erase(s[i]);
        }
        
        return res;
    }
    
  private:
    unordered_set<char> unique_chs_;
};

