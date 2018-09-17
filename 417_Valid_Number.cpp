/*
417. Valid Number
Validate if a given string is numeric.

Example
"0" => true

" 0.1 " => true

"abc" => false

"1 a" => false

"2e10" => true


Author: Yuan Li
Date: 9/16/2018 
Difficulty: Hard
*/

#include <boost/algorithm/string.hpp>

class Solution {
public:
    /**
     * @param s: the string that represents a number
     * @return: whether the string is a valid number
     */
    bool isNumber(string &s) {
        // write your code here
        if (s.empty()) {
            return false;
        }
        
        boost::trim(s);
        int len = s.length();
        s += " "; // trick: adding " " to prevent index overflow in the following operations
        
        int i = 0;
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        
        int n_digit = 0, n_dot = 0;
        while (isdigit(s[i]) || s[i] == '.') {
            if (isdigit(s[i])) {
                ++n_digit;
            }
            if (s[i] == '.') {
                ++n_dot;
            }
            ++i;
        }
        if (n_digit == 0 || n_dot > 1) {
            return false;
        }
        
        if (s[i] == 'e') {
            ++i;
            if (s[i] == '+' || s[i] == '-') {
                ++i;
            }
            
            if (i == len) {
                return false;
            }
            
            for (; i < len; ++i) {
                if (!isdigit(s[i])) {
                    return false;
                }
            }
        }
        
        return i == len;
    }
};
