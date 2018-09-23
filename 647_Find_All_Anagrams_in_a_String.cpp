/*
647. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 40,000.

The order of output does not matter.

Example
Given s = "cbaebabacd" p = "abc"

return [0, 6]

The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".


Author: Yuan Li
Date: 9/22/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        // write your code here
        vector<int> res;
        if (s.length() < p.length()) {
            return res;
        }
        
        vector<int> det(256, 0);
        int i = 0;
        for (; i < p.length(); ++i) {
            // det[c] = cnt_s[c] - cnt_p[c]
            ++det[s[i]];
            --det[p[i]];
        }
        
        int abs_sum = 0;
        for (const int &d : det) {
            abs_sum += abs(d);
        }
        if (abs_sum == 0) {
            res.push_back(0);
        }
        
        for (; i < s.length(); ++i) {
            int start = s[i - p.length()];
            int end = s[i];
        
            abs_sum -= abs(det[start]) + abs(det[end]);
            --det[start];
            ++det[end];
            abs_sum += abs(det[start]) + abs(det[end]);
        
            if (abs_sum == 0) {
                res.push_back(i - p.length() + 1);
            }
        }
        
        return res;
    }
};
