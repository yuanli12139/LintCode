/*
158. Valid Anagram
Write a method anagram(s,t) to decide if two strings are anagrams or not.

Example
Given s = "abcd", t = "dcab", return true.
Given s = "ab", t = "ab", return true.
Given s = "ab", t = "ac", return false.

Challenge
O(n) time, O(1) extra space

Clarification
What is Anagram?

Two strings are anagram if they can be the same after change the order of characters.


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t) {
        // write your code here
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> ch_cnt; // O(len(ascii)) = O(1)
        for (char c : s) {
            ch_cnt[c] = ch_cnt.count(c) ? ch_cnt[c] + 1 : 1;
        }
        
        for (char c : t) {
            if (!ch_cnt.count(c) || --ch_cnt[c] < 0) {
                return false;
            }
        }
        
        for (auto kv : ch_cnt) {
            if (kv.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};
