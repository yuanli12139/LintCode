/*
442. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example
insert("lintcode")
search("code")
>>> false
startsWith("lint")
>>> true
startsWith("linterror")
>>> false
insert("linterror")
search("lintcode)
>>> true
startsWith("linterror")
>>> true

Notice
You may assume that all inputs are consist of lowercase letters a-z.

Reference
https://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/


Author: Yuan Li
Date: 9/2/2018 
Difficulty: Medium
*/

// time: O(l)
// space: O(prefixes) = O(n * l^2)
class Solution {
  public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        if (s.empty()) {
            return 0;
        }
    
        str_ways_[""] = 1;
        
        return helper(s);
    }
  
  private:
    int helper(const string &s) {
        if (str_ways_.count(s)) {
            return str_ways_[s];
        }    
        
        if (s[0] == '0') {
            return 0;
        }
        
        if (s.length() == 1) {
            return 1;
        }
        
        // remove the 1st character
        int n = helper(s.substr(1)); //string::substr() is O(n)
        
        // remove the 1st 2 characters
        if (stoi(s.substr(0, 2)) <= 26) {
            n += helper(s.substr(2));
        }
        
        str_ways_[s] = n;
        return n;
    }
    
  private:
    unordered_map<string, int> str_ways_;
};


// using start index to get rid of substr() call
// time: O(n)
// space: O(n)
class Solution {
  public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        if (s.empty()) {
            return 0;
        }
    
        return helper(s, 0);
    }
  
  private:
    int helper(const string &s, int start) {
        if (str_ways_.count(start)) {
            return str_ways_[start];
        }    
        
        if (s[start] == '0') {
            return 0;
        }
        
        // single charactr or empty
        if (start >= s.length() - 1) { 
            return 1;
        }
        
        // remove the 1st character
        int n = helper(s, start + 1);
        
        // remove the 1st 2 characters
        if ((s[start] - '0') * 10 + (s[start+1] - '0') <= 26) {
            n += helper(s, start + 2);
        }
        
        str_ways_[start] = n;
        return n;
    }
    
  private:
    unordered_map<int, int> str_ways_;
};


// dynamic programming
// time: O(n)
// space: O(1)
class Solution {
  public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        if (s.length() == 1) {
            return 1;
        }
        
        // initialize for ""
        int dp1 = 1; // dp[i-1]
        int dp2 = 1; // dp[i-2]
        
        for (int i = 1; i < s.length(); ++i) {
            int dp = 0;
            if (!isValid(s[i]) && !isValid(s[i-1], s[i])) {
                return 0;
            }
            
            if (isValid(s[i])) {
                dp += dp1;
            }
            
            if (isValid(s[i-1], s[i])) {
                dp += dp2;
            }
            
            dp2 = dp1;
            dp1 = dp;
        }
        
        return dp1;
    }
    
  private:
    bool isValid(const char c) {
        return c != '0';
    }
    
    bool isValid(const char c1, const char c) {
        int n = (c1 - '0') * 10 + (c - '0');
        return n >= 10 && n <= 26;
    }
};
