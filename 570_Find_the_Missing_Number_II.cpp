/*
570. Find the Missing Number II
Giving a string with number from 1-n in random order, but miss 1 number.Find that number.

n <= 30

Example
Given n = 20, str = 19201234567891011121314151618

return 17


Author: Yuan Li
Date: 7/15/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        // write your code here
        vector<bool> foundNums(n, false);
        return dfs(str, foundNums, 0);
    }
    
    int dfs(string &str, vector<bool> &foundNums, int startIdx) {
        if (startIdx == str.length()) {
            if (count(foundNums.begin(), foundNums.end(), false) != 1)
                return -1;
            else
                // return distance(foundNums.begin(), find(
                //         foundNums.begin(), foundNums.end(), false)) + 1;
                return find(foundNums.begin(), foundNums.end(), false) - foundNums.begin() + 1;
        }
        
        int n = foundNums.size();
        int missing = -1;
        for (int i = startIdx; i < startIdx + 2 && i < str.length(); ++i) {
            int num = stoi(str.substr(startIdx, i - startIdx + 1)); 
            if (num == 0)
                return -1;
            
            if (num > n || foundNums[num-1])
                continue;
                
            foundNums[num-1] = true;
            
            missing = dfs(str, foundNums, i + 1);
            if (missing != -1)
                break;
            
            foundNums[num-1] = false;
        }
        
        return missing;
    }
};
