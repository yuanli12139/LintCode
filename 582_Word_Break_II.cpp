/*
582. Word Break II
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].

A solution is ["lint code", "lint co de"].


Author: Yuan Li
Date: 7/15/2018 
Difficulty: Hard
*/

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
        unordered_map<string, vector<string>> memo;
        
        return dfs(s, wordDict, memo);
    }
    
    vector<string> dfs(string &s, unordered_set<string> &wordDict, 
                      unordered_map<string, vector<string>> &memo) {
        vector<string> res;
        if (s.length() == 0)
            return res;

        if (memo.find(s) != memo.end())
            return memo[s];
            
        if (wordDict.find(s) != wordDict.end()) {
            res.push_back(s);
        }
            
        for (int len = 1; len < s.length(); ++len) {
            string word = s.substr(0, len);
            
            if (wordDict.find(word) == wordDict.end()) 
                continue;
        
            string suffix = s.substr(len);
            vector<string> segs = dfs(suffix, wordDict, memo);
            
            for (string seg : segs) {
                res.push_back(word + ' ' + seg);
            }
        }
        
        memo[s] = res;
        
        return res;
    }
};
