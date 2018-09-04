/*
916. Palindrome Permutation
Given a string, determine if a permutation of the string could form a palindrome.

Example
Given s = "code", return False.
Given s = "aab", return True.
Given s = "carerac", return True.


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here
        unordered_map<char, int> ch_cnt;
        for (char c : s) {
            if (!ch_cnt.count(c)) {
                ch_cnt[c] = 1;
            } else {
                ch_cnt[c] += 1;
            }
        }
        
        int odd_cnt = 0;
        for (auto kv : ch_cnt) {
            odd_cnt += kv.second % 2;
        }
        
        return odd_cnt <= 1;
    }
};
