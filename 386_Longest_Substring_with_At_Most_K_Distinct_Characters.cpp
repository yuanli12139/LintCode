/*
386. Longest Substring with At Most K Distinct Characters
Given a string s, find the length of the longest substring T that contains at most k distinct characters.

Example
For example, Given s = "eceba", k = 3,

T is "eceb" which its length is 4.

Challenge
O(n), n is the size of the string s.


Author: Yuan Li
Date: 9/20/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int res = 0;
        
        int n = s.length();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && (ch_cnt_.size() < k || ch_cnt_.count(s[j]))) {
                ++ch_cnt_[s[j++]];
            }
            
            // constraint satisfied
            res = max(res, j - i);
            
            // i moves on
            if (ch_cnt_.count(s[i])) {
                if (--ch_cnt_[s[i]] == 0) {
                    ch_cnt_.erase(s[i]);
                }
            }
        }
        
        return res;
    }
    
  private:
    unordered_map<char, int> ch_cnt_;
};

