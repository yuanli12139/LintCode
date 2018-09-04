/*
772. Group Anagrams
Given an array of strings, group anagrams together.

Example
Given strs = ["eat", "tea", "tan", "ate", "nat", "bat"],
Return 
[
    ["ate", "eat","tea"],
    ["nat","tan"],
    ["bat"]
]

Notice
All inputs will be in lower-case.


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param strs: the given array of strings
     * @return: The anagrams which have been divided into groups
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<string>> anagrams;
        for (const string &str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            anagrams[sorted_str].push_back(str);
        }
        
        vector<vector<string>> res;
        for (auto &kv : anagrams) {
            vector<string> group;
            for (const string &str : kv.second) {
                group.push_back(str);
            }
            
            res.push_back(group);
        }
        
        return res;
    }
};
