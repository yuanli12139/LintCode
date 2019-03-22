/*
656. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2

Example
Example1

Input:
"123"
"45"

Output:
"5535"

Explanation:
123 x 45 = 5535

Example2

Input:
"0"
"0"

Output:
"0"

Notice
The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


Author: Yuan Li
Date: 3/21/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return product of num1 and num2
     */
    string multiply(string &num1, string &num2) {
        // write your code here
        int l1 = num1.length(), l2 = num2.length();
        
        vector<int> tmp(l1 + l2 + 1, 0); // tmp.size() >= 1
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                tmp[i+j] += (num1[l1-1 - i] - '0') * (num2[l2-1 - j] - '0'); 
            }
        }
        
        // tmp is reversed
        for (int i = 1; i < l1 + l2; ++i) {
            tmp[i] += tmp[i-1] / 10;
            tmp[i-1] %= 10;
        }
        
        int i = l1 + l2 - 1;
        
        // skip leading 0s
        while (i > 0 && tmp[i] == 0) {
            --i;
        }
        
        string res;
        while (i >= 0) {
            res += to_string(tmp[i--]);
        }
        
        return res;
    }
};

