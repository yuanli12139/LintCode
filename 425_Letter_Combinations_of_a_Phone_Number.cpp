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
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }
        
        unordered_map<char, string> digit2letters;
        digit2letters['2'] = "abc";
        digit2letters['3'] = "def";
        digit2letters['4'] = "ghi";
        digit2letters['5'] = "jkl";
        digit2letters['6'] = "mno";
        digit2letters['7'] = "pqrs";
        digit2letters['8'] = "tuv";
        digit2letters['9'] = "wxyz";
        
        string comb;
        dfs(digits, comb, digit2letters, res);
        
        return res;
    }
    
    void dfs(string &digits, string comb, 
            unordered_map<char, string> &digit2letters, vector<string> &res) {
        if (comb.length() == digits.length()) {
            res.push_back(comb);
            return;
        }
        
        char digit = digits[comb.size()];
        for (char c : digit2letters[digit]) {
            // comb += c;
            comb.push_back(c);
            dfs(digits, comb, digit2letters, res);
            comb.pop_back();
        }
    }
};
