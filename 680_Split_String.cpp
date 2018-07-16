/*
680. Split String
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

Example
Given the string "123"
return [["1","2","3"],["12","3"],["1","23"]]


Author: Yuan Li
Date: 7/15/2018 
Difficulty: Easy
*/

class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here
        vector<vector<string>> res;
        vector<string> comb;
        
        if (s.length() == 0) {
            res.push_back(comb);
            return res;
        }
            
        dfs(s, comb, 0, res);
        return res;
    }
    
    void dfs(string& s, vector<string> comb, int startIdx, vector<vector<string>>& res) {
        if (startIdx == s.length()) {
            res.push_back(comb);
            return;
        }
        
        for (int i = startIdx; i < startIdx + 2 && i < s.length(); ++i) {
            comb.push_back(s.substr(startIdx, i - startIdx + 1));
            dfs(s, comb, i + 1, res);
            comb.pop_back();
        }
    }
};
