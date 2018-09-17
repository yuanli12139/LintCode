/*
659. Encode and Decode Strings
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Please implement encode and decode

Example
Given strs = ["lint","code","love","you"]
string encoded_string = encode(strs)

return ["lint","code","love","you"] when you call decode(encoded_string)


Author: Yuan Li
Date: 9/16/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string res;
        for (string str : strs) {
            for (char c : str) {
                if (c == ':') {
                    res += "::";
                } else {
                    res += c;
                }
            }
            res += ":;";
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> res;
        string item;
        int i = 0;
        while (i < str.length()) {
            if (str[i] == ':') { // escape
                if (str[i+1] == ';') { // connector
                    res.push_back(item);
                    item.clear();
                    i += 2;
                } else {
                    item += str[i+1]; // ':'
                    i += 2;
                }
            } else {
                item += str[i++];
            }
        }
        return res;
    }
};
