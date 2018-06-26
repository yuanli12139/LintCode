/*
415. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.

Example
"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Challenge
O(n) time without extra memory.


Author: Yuan Li
Date: 6/25/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        vector<char> valid;
        for (auto c : s) {
            if (isalnum(c)) {
                valid.push_back(tolower(c));
            }
        }
        
        int i = (valid.size() - 1) / 2;
        int j = valid.size() / 2;
        
        while (i >= 0 && j < valid.size()) {
            if (valid[i] != valid[j]) {
                return false;
            }
            
            i--;
            j++;
        }
        
        return true;
    }
};
