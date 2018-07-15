/*
192. Wildcard Matching
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false


Author: Yuan Li
Date: 7/15/2018 
Difficulty: Hard
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        vector<vector<bool>> isVisited(s.length(), vector<bool>(p.length(), 0));
        vector<vector<bool>> memo(s.length(), vector<bool>(p.length(), 0));
        
        return dfs(s, 0, p, 0, isVisited, memo);
    }
    
    bool dfs(string &s, int sIdx, string &p, int pIdx, 
            vector<vector<bool>> &isVisited, vector<vector<bool>> &memo) {
        // if p is empty, s must be empty as well
        if (pIdx == p.length())
            return sIdx == s.length();
        
        // if s is empty, p must be either empty or all *'s
        if (sIdx == s.length())
            return allStar(p, pIdx);
        
        // memoization
        if (isVisited[sIdx][pIdx])
            return memo[sIdx][pIdx];
            
        isVisited[sIdx][pIdx] = true;
            
        bool match;
        if (p[pIdx] == '*') {
            match = dfs(s, sIdx, p, pIdx + 1, isVisited, memo) || 
                    dfs(s, sIdx + 1, p, pIdx, isVisited, memo);
        }
        else {
            match = isCharMatch(s, sIdx, p, pIdx) && 
                    dfs(s, sIdx + 1, p, pIdx + 1, isVisited, memo);
        }
    
        memo[sIdx][pIdx] = match;        
        
        return match;            
    }
    
    bool allStar(string &s, int idx) {
        for (int i = idx; i < s.length(); ++i) {
            if (s[i] != '*')
                return false;
        }
        
        return true;
    }
    
    bool isCharMatch(string &s, int sIdx, string &p, int pIdx) {
        return s[sIdx] == p[pIdx] || p[pIdx] == '?';
    }
};
