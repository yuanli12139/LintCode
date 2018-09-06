/*
425. Letter Combinations of a Phone Number
Given a digit string excluded 01, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Picture
https://lintcode-media.s3.amazonaws.com/problem/200px-Telephone-keypad2.svg.png

Although the above answer is in lexicographical order, your answer could be in any order you want.

Example
Given "23"

Return ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]


Author: Yuan Li
Date: 7/21/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    Solution () {
        digit_letters_['2'] = "abc";
        digit_letters_['3'] = "def";
        digit_letters_['4'] = "ghi";
        digit_letters_['5'] = "jkl";
        digit_letters_['6'] = "mno";
        digit_letters_['7'] = "pqrs";
        digit_letters_['8'] = "tuv";
        digit_letters_['9'] = "wxyz";
    } 
     
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }
        
        string comb;
        dfs(digits, comb, res);
        
        return res;
    }
    
  private:
    unordered_map<char, string> digit_letters_;
        
  private:
    void dfs(string &digits, string comb, vector<string> &res) {
        if (comb.length() == digits.length()) {
            res.push_back(comb);
            return;
        }
        
        char digit = digits[comb.size()];
        for (char c : digit_letters_[digit]) {
            // comb += c;
            comb.push_back(c);
            dfs(digits, comb, res);
            comb.pop_back();
        }
    }
};
