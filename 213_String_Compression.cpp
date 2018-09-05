/*
213. String Compression
Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.

If the "compressed" string would not become smaller than the original string, your method should return the original string.

You can assume the string has only upper and lower case letters (a-z).

Example
str=aabcccccaaa return a2b1c5a3
str=aabbcc return aabbcc
str=aaaa return a4


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param originalString: a string
     * @return: a compressed string
     */
    string compress(string &originalString) {
        // write your code here
        string res;
        
        int cnt = 0;
        for (char c : originalString) { 
            if (res.empty()) {
                res += c;
                ++cnt;
                continue;
            }
            
            if (c != res.back()) {
                res += to_string(cnt); 
                res += c;
                cnt = 1;
            } else {
                ++cnt;
            }
            
            // early stop
            if (res.length() >= originalString.length()) {
                return originalString;
            }
        }
        
        res += to_string(cnt);
        
        return res.length() < originalString.length() ? res : originalString;
    }
};
