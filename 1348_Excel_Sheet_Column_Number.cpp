/*
1348. Excel Sheet Column Number
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

Example
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int titleToNumber(string &s) {
        // write your code here
        int res = 0, n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            char c = s[n-1-i];
            res += (c - ('A' - 1)) * pow(26, i); 
        }
        
        return res;
    }
};
