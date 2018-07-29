/*
365. Count 1 in Binary
Count how many 1 in binary representation of a 32-bit integer.

Example
Given 32, return 1

Given 5, return 2

Given 1023, return 9

Challenge
If the integer is n bits with m 1 bits. Can you do it in O(m) time?


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Easy
*/

class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int cnt = 0;
        
        // 12: 1100 &= 1011 -> 1000 &= 0111 -> 0000 
        while (num != 0) {
            num &= num - 1;
            cnt++;
        }
        
        return cnt;
    }
};
