/*
776. Strobogrammatic Number II
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.

Example
Given n = 2, return ["11","69","88","96"].

Reference
http://www.cnblogs.com/grandyang/p/5200919.html


Author: Yuan Li
Date: 11/18/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    vector<string> findStrobogrammatic(int n) {
        // write your code here
        return dfs(n, n);
    }

  private:
    vector<string> dfs(int n, int remain) {
        if (remain == 0) {
            return {""};
        }
        if (remain == 1) {
            return {"0", "1", "8"};
        }
        
        vector<string> yolks = dfs(n, remain - 2), eggs;
        
        for (auto yolk : yolks) {
            if (remain != n) {
                eggs.push_back("0" + yolk + "0");
            }
            eggs.push_back("1" + yolk + "1");
            eggs.push_back("6" + yolk + "9");
            eggs.push_back("8" + yolk + "8");
            eggs.push_back("9" + yolk + "6");
        }
        
        return eggs;
    }
};

