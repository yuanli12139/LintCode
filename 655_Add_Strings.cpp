/*
655. Add Strings

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Example
Example 1:

Input : num1 = "123", num2 = "45"
Output : 168

Notice
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


Author: Yuan Li
Date: 3/21/2019 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        // write your code here
        string res;
        
        int carry = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; --i, --j) {
            int sum = carry + (i >= 0) * (num1[i] - '0') + (j >= 0) * (num2[j] - '0');
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }
        
        if (carry) {
            res = to_string(carry) + res;
        }
        
        return res;
    }
};

