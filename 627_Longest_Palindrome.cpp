/*
627. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Assume the length of given string will not exceed 1010.

Example
Given s = "abccccdd" return 7

One longest palindrome that can be built is "dccaccd", whose length is 7.


Author: Yuan Li
Date: 6/25/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here
        set<char> table;
        for (auto c : s) {
            if (table.find(c) == table.end()) {
                table.insert(c);
            }
            else {
                table.erase(c);
            }
        }
        
        int n_remove = table.size();
        if (n_remove) {
            n_remove--;
        }
            
        return s.length() - n_remove;
    }
};
