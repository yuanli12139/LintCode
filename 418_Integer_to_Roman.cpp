/*
418. Integer to Roman

Given an integer, convert it to a roman numeral.

The number is guaranteed to be within the range from 1 to 3999.

Example
Example 1:

Input: 1
Output: "I"

Example 2:

Input: 99
Output: "XCIX"

Clarification
What is Roman Numeral?

https://en.wikipedia.org/wiki/Roman_numerals
https://zh.wikipedia.org/wiki/罗马数字
http://baike.baidu.com/view/42061.htm


Author: Yuan Li
Date: 3/20/2019 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param n: The integer
     * @return: Roman representation
     */
    string intToRoman(int n) {
        // write your code here
        return M_[n/1000] + C_[n/100%10] + X_[n/10%10] + I_[n%10];
    }
    
  private:
    vector<string> M_ = {"", "M", "MM", "MMM"};
    vector<string> C_ = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> X_ = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> I_ = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
};

