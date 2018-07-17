/*
780. Remove Invalid Parentheses
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

The input string may contain letters other than the parentheses ( and ).

Example
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]


Author: Yuan Li
Date: 7/16/2018 
Difficulty: Hard
*/

class Solution {
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    vector<string> removeInvalidParentheses(string &s) {
        // Write your code here
        unordered_set<string> combs;
        string comb(s);
        
        int maxK = count(s.begin(), s.end(), '(') + count(s.begin(), s.end(), ')');
        for (int k = 0; k <= maxK; ++k) {
            dfs(k, comb, 0, combs);
            
            if (!combs.empty())
                break;
        }
        
        vector<string> res(combs.begin(), combs.end()); 
        return res;
    }
    
    void dfs(int remainK, string comb, int idx, 
            unordered_set<string> &combs) {
        if (remainK == 0) {
            //if (isValidParentheses(comb)) {
            if (isValidParentheses(comb, comb.length())) {
                combs.insert(comb);
            }
            
            return;
        }
        
        //if (idx == comb.length() || comb.length() - idx < remainK)
        if (idx == comb.length() || comb.length() - idx < remainK || 
            !isValidParentheses(comb, idx))
            return;
            
        char p = comb[idx];
        if (p == '(' || p == ')') {
            // remove this parenthese
            comb.erase(idx, 1);
            dfs(remainK - 1, comb, idx, combs);
            
            // do not remove this parenthese 
            comb.insert(idx, 1, p);
            dfs(remainK, comb, idx + 1, combs);
        } else { // p is a letter
            dfs(remainK, comb, idx + 1, combs);
        }
    }
    
    bool isValidParentheses(string &s) {
        int cntL = 0, cntR = 0;
        for (char c : s) {
            if (c == '(') {
                cntL++;
            } else if (c == ')') {
                cntR++;
            }
            
            if (cntR > cntL)
                return false;
        }
        
        cntL = 0; cntR = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '(') {
                cntL++;
            } else if (c == ')') {
                cntR++;
            }
            
            if (cntL > cntR)
                return false;
        }
        
        return true;
    }
    
    // optimized isValidParentheses
    bool isValidParentheses(string &s, int idx) {
        int cntL = 0, cntR = 0;
        for (int i = 0; i < idx; ++i) {
            char c = s[i];
            if (c == '(') {
                cntL++;
            } else if (c == ')') {
                cntR++;
            }
            
            if (cntR > cntL)
                return false;
        }
    
        if (idx < s.length())
            return true;
            
        cntL = 0; cntR = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '(') {
                cntL++;
            } else if (c == ')') {
                cntR++;
            }
            
            if (cntL > cntR)
                return false;
        }
        
        return true;
    }
};
