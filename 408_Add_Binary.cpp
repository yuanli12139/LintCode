/*
408. Add Binary

Given two binary strings, return their sum (also a binary string).

Example
Example 1:

Input:
a = "0", b = "0"
Output:
"0"

Example 2:

Input:
a = "11", b = "1"
Output:
"100"


Author: Yuan Li
Date: 3/23/2019 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        // write your code here
        string res;
        
        int carry = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; --i, --j) {
            int sum = (i >= 0) * (a[i] - '0') + (j >= 0) * (b[j] - '0') + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        
        if (carry) {
            res = "1" + res;
        }
        
        return res;
    }
};

