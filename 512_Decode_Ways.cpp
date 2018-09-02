/*
512. Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example
Given encoded message 12, it could be decoded as AB (1 2) or L (12).
The number of ways decoding 12 is 2.

Reference
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-91-decode-ways/


Author: Yuan Li
Date: 9/1/2018 
Difficulty: Medium
*/

// time: O(n^2)
// space: O(n^2)
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
