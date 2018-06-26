/*
200. Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Example
Given the string = "abcdzdcab", return "cdzdc".

Challenge
O(n^2) time is acceptable. Can you do it in O(n) time.


Author: Yuan Li
Date: 6/25/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        if (s.length() == 0) {
            return "";
        }
         
        int start = 0, longest = 0, length = 0;
        for (int i = 0; i < s.length(); i++) {
            length = findLongestPalindrome(s, i, i);
            if (length > longest) {
                longest = length;
                start = i - longest / 2;
            }
            
            length = findLongestPalindrome(s, i, i+1);
            if (length > longest) {
                longest = length;
                start = i - longest / 2 + 1;
            }
        }
        
        return s.substr(start, longest);
    }
    
    int findLongestPalindrome(string &s, int left, int right) {
        int length = 0;
        while (left >= 0 && right < s.length()) {
            if (s[left] == s[right]) {
                if (left == right) {
                    length++;
                }
                else {
                    length += 2;
                } 
                
                left--;
                right++;
            }
            else 
                break;
        }
        
        return length;
    }
};
