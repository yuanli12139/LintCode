/*
829. Word Pattern II
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.(i.e if a corresponds to s, then b cannot correspond to s. For example, given pattern = "ab", str = "ss", return false.)

You may assume both pattern and str contains only lowercase letters.

Example
Given pattern = "abab", str = "redblueredblue", return true.
Given pattern = "aaaa", str = "asdasdasdasd", return true.
Given pattern = "aabb", str = "xyzabcxzyabc", return false.


Author: Yuan Li
Date: 7/21/2018 
Difficulty: Hard
*/

class Solution {
  public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        // write your code here
        return dfs(pattern, str);
    }
  
  private:
    unordered_map<char, string> pattern2str_;
    unordered_set<string> mapped_;
  
  private:
    bool dfs(string &pattern, string &str) {
        if (pattern.length() == 0) {
            return str.length() == 0;
        }        
        
        char p = pattern[0];
        if (pattern2str_.count(p)) {
            string match = pattern2str_[p];
            if (!startsWith(str, match)) {
                return false;
            }
            
            string remainPattern = pattern.substr(1);
            string remainStr = str.substr(match.length());
            
            return dfs(remainPattern, remainStr);
        }
        
        for (int i = 0; i < str.length(); ++i) {
            string s = str.substr(0, i+1); 
            if (mapped_.count(s)) {
                continue;
            }
            
            pattern2str_[p] = s;
            mapped_.insert(s);
            
            string remainPattern = pattern.substr(1);
            string remainStr = str.substr(i+1);
            if (dfs(remainPattern, remainStr)) {
                return true;                
            }
            
            pattern2str_.erase(p);
            mapped_.erase(s);
        }
        
        return false;
    }
        
    bool startsWith(string &str, string &match) {
        if (str.length() < match.length()) {
            return false;
        }
        
        return str.substr(0, match.length()) == match;
    }
};
