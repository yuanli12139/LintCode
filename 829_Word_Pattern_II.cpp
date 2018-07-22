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
Difficulty: Medium
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
        unordered_map<char, string> pattern2str;
        unordered_set<string> mapped;
        
        return dfsMatch(pattern, str, pattern2str, mapped);
    }
    
    bool dfsMatch(string &pattern, string &str, 
            unordered_map<char, string> pattern2str,
            unordered_set<string> mapped) {
            if (pattern.length() == 0) {
                return str.length() == 0;
            }        
            
            char p = pattern[0];
            if (pattern2str.count(p)) {
                string match = pattern2str[p];
                if (!startsWith(str, match)) {
                    return false;
                }
                
                string remainPattern = pattern.substr(1);
                string remainStr = str.substr(match.length());
                return dfsMatch(remainPattern, remainStr, pattern2str, mapped);
            }
            
            for (int i = 0; i < str.length(); ++i) {
                string s = str.substr(0, i+1); 
                if (mapped.count(s)) {
                    continue;
                }
                
                pattern2str[p] = s;
                mapped.insert(s);
                
                string remainPattern = pattern.substr(1);
                string remainStr = str.substr(i+1);
                if (dfsMatch(remainPattern, remainStr, pattern2str, mapped)) {
                    return true;                
                }
                
                pattern2str.erase(p);
                mapped.erase(s);
            }
            
            return false;
        }
        
    bool startsWith(string &str, string &match) {
        if (str.length() < str.length()) {
            return false;
        }
        
        return str.substr(0, match.length()) == match;
    }
};
