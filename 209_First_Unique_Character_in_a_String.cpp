/*
209. First Unique Character in a String
Find the first unique character in a given string. You can assume that there is at least one unique character in the string.

Example
For "abaccdeff", return 'b'.

Challenge
不使用额外的存储空间。


Author: Yuan Li
Date: 7/24/2018 
Difficulty: Easy
*/

// hash table
class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here
        unordered_map<char, pair<int, int>> ch2ctIdx;
        for (int i = 0; i < str.length(); ++i) {
            char c = str[i];
            if (!ch2ctIdx.count(c)) {
                ch2ctIdx[c] = pair<int, int> {1, i};
            } else {
                ch2ctIdx[c].first++;
            }
        }
        
        int idx = str.length() - 1;
        for (auto p : ch2ctIdx) {
            if (p.second.first > 1) {
                continue;
            }
            
            if (p.second.second < idx) {
                idx = p.second.second;
            }
        }
        
        return str[idx];
    }
};
