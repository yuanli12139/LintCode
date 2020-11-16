/*
32. Minimum Window Substring
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Example
For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"

Challenge
Can you do it in time complexity O(n) ?

Clarification
Should the characters in minimum window has the same order in target?

Not necessary.

Notice
If there is no such window in source that covers all characters in target, return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.
The target string may contain duplicate characters, the minimum window should cover all characters including the duplicate characters in target.

Reference
https://www.youtube.com/watch?v=dzdtzymjM7A
https://www.youtube.com/watch?v=9qFR2WQGqkU


Author: Yuan Li
Date: 8/25/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        if (source.length() < target.length()) {
            return "";
        }
        
        unordered_map<char, int> tChar_cnt;
        for (char c : target) {
            // if (tChar_cnt.count(c)) {
            //     tChar_cnt[c]++;
            // } else {
            //     tChar_cnt[c] = 1;
            // }
            ++tChar_cnt[c];
        }
        
        int start = -1;
        int remain = target.length();
        int min_len = INT_MAX;
        for (int i = 0, j = 0; j < source.length(); ++j) {
            // move j to include all target chars
            char ch = source[j];
            if (tChar_cnt.count(ch) && tChar_cnt[ch]-- > 0) {
                --remain;
            }
            
            // move i to find the best start
            while (remain == 0) {
                if (j - i + 1 < min_len) {
                    start = i;
                    min_len = j - i + 1;
                }
                
                // update count when i moves on
                char left_most = source[i++]; 
                if (tChar_cnt.count(left_most) && ++tChar_cnt[left_most] > 0) {
                    ++remain;
                }
            }
        }

        return (start != -1) ? source.substr(start, min_len) : "";
    }
};


// Date: 9/20/2018
class Solution {
  public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        if (source.empty()) {
            return "";
        }
        
        for (char c : target) {
            ++target_cnt_[c];
        }
        
        int matched_unique_chs = 0;
        int target_unique_chs = target_cnt_.size();
        
        int n = source.size();
        int start = -1, end = n;
        
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && matched_unique_chs < target_unique_chs) {
                if (target_cnt_.count(source[j])) {
                    ++source_cnt_[source[j]];
                    matched_unique_chs += source_cnt_[source[j]] == target_cnt_[source[j]];
                }
                ++j;
            }
            
            // j == n
            if (matched_unique_chs < target_unique_chs) {
                break;
            }
            
            // found match
            if (j - i < end - start) {
                start = i;
                end = j;
            }
            
            // remove source[i] from the window
            if (target_cnt_.count(source[i])) {
                matched_unique_chs -= source_cnt_[source[i]] == target_cnt_[source[i]];
                --source_cnt_[source[i]];
            }
        }
        
        return start == -1 ? "" : source.substr(start, end - start);
    }
    
  private:
    unordered_map<char, int> source_cnt_, target_cnt_;
};

