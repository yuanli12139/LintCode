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
        return dfs(s, wordDict);
    }
    
  private:
    unordered_map<string, vector<string>> memo_;
  
  private:
    vector<string> dfs(string &s, unordered_set<string> &wordDict) {
        vector<string> res;
        if (s.empty()) {
            return res;
        }

        if (memo_.count(s)) {
            return memo_[s];
        }
            
        if (wordDict.count(s)) {
            res.push_back(s);
        }
            
        for (int len = 1; len < s.length(); ++len) {
            string word = s.substr(0, len);
            
            if (!wordDict.count(word)) { 
                continue;
            }
        
            string suffix = s.substr(len);
            vector<string> segs = dfs(suffix, wordDict);
            
            for (string seg : segs) {
                res.push_back(word + ' ' + seg);
            }
        }
        
        memo_[s] = res;
        
        return res;
    }
};
