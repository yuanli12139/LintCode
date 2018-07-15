/*
136. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example
Given s = "aab", return:

[
  ["aa","b"],
  ["a","a","b"]
]


Author: Yuan Li
Date: 7/14/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<vector<string>> res;
        vector<string> comb;
        
        if (s.length() == 0) 
            return res;
            
        dfs(s, comb, 0, res);
        
        return res;
    }
    
    void dfs(string &s, vector<string> comb, int startIdx, 
            vector<vector<string>> &res) {
        if (startIdx == s.length()) {
            res.push_back(comb);
            return;
        }
        
        for (int i = startIdx; i < s.length(); ++i) {
            string subs = s.substr(startIdx, i - startIdx + 1);
            if (!isPalindrome(subs))
                continue;
            
            comb.push_back(subs);
            dfs(s, comb, i + 1, res);
            comb.pop_back();
        }
    }
    
    bool isPalindrome(string &s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        
        return true;
    }
};
