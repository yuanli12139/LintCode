/*
154. Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


The function prototype should be:

bool isMatch(string s, string p)

Example
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true


Author: Yuan Li
Date: 7/15/2018 
Difficulty: Hard
*/

class Solution {
  public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        visited_.resize(s.length(), vector<bool>(p.length(), false));
        memo_.resize(s.length(), vector<bool>(p.length(), false));
        
        return dfs(s, 0, p, 0);
    }
    
  private:
    vector<vector<bool>> visited_;
    vector<vector<bool>> memo_;
    
  private:
    bool dfs(string &s, int sIdx, string &p, int pIdx) {
        if (pIdx == p.length()) 
            return sIdx == s.length();
            
        if (sIdx == s.length())
            // must be _*_*_* pattern
            return isEmpty(p, pIdx);
            
        if (visited_[sIdx][pIdx]) 
            return memo_[sIdx][pIdx];
            
        visited_[sIdx][pIdx] = true;
        
        char sChar = s[sIdx], pChar = p[pIdx];
        bool match;
        
        // _*: can either match empty or a '_'
        if (pIdx + 1 < p.length() && p[pIdx+1] == '*') {
            match = dfs(s, sIdx, p, pIdx + 2) ||
                    (isCharMatch(sChar, pChar) && dfs(s, sIdx + 1, p, pIdx));
        } else {
            // _: must match the character
            match = isCharMatch(sChar, pChar) && dfs(s, sIdx + 1, p, pIdx + 1);
        }
        
        memo_[sIdx][pIdx] = match;
        
        return match;
    }
    
    bool isEmpty(string &p, int pIdx) {
        for (int i = pIdx; i < p.length(); i += 2) {
            if (i == p.length() - 1 || p[i+1] != '*') {
                return false;
            }
        }
        
        return true;
    }    
    
    bool isCharMatch(char sChar, char pChar) {
        return sChar == pChar || pChar == '.';
    }
};
