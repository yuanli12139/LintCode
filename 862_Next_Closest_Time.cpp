/*
862. Next Closest Time
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example
Given time = "19:34", return "19:39".

Explanation: 
The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later. It is not 19:33, because this occurs 23 hours and 59 minutes later.
Given time = "23:59", return "22:22".

Explanation: 
The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.


Author: Yuan Li
Date: 7/22/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        // write your code here
        string res;
        
        vector<int> hands = {4, 3, 1, 0};
        char minDigit = '9';
        for (int i : hands) {
            char digit = time[i];
            if (digit < minDigit) {
                minDigit = digit;
            }
        }
        
        for (int i : hands) {
            char minGreater = '9';
            bool has_minGreater = false;
            
            for (int j : hands) {
                if (j == i) {
                    continue;
                }
                
                if (time[j] > time[i] && time[j] <= minGreater) {
                    minGreater = time[j];
                    has_minGreater = true;
                }
            }
            
            if (has_minGreater) {
                string next_time = time;
                
                // next_time[i] = minGreater
                next_time.replace(i, 1, 1, minGreater);
                
                for (int k : hands) {
                    if (k > i) {
                        // next_time[k] = minDigit;
                        next_time.replace(k, 1, 1, minDigit);
                    }
                }
                
                if (isValid(next_time)) {
                    return next_time;
                }
            }
        }
        
        res = time;
        for (int i : hands) {
            // res[i] = minDigit;
            res.replace(i, 1, 1, minDigit);
        }

        return res;
    }
    
    bool isValid(string &time) {
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));
        
        return hh >= 0 && hh < 24 && mm >= 0 && mm < 60;
    }
};
