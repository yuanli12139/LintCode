/*
1116. Exclusive Time of Functions
Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions.

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts from the very beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.

Example
Input:
n = 2
logs = 
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
Explanation:
Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1. 
Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time. 
So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.

Notice
Input logs will be sorted by timestamp, NOT log id.
Your output should be sorted by function id, which means the 0th element of your output corresponds to the exclusive time of function 0.
Two functions won't start or end at the same time.
Functions could be called recursively, and will always end.
1 <= n <= 100 


Author: Yuan Li
Date: 9/3/2018 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param n: a integer
     * @param logs: a list of integers
     * @return: return a list of integers
     */
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        // write your code here
        vector<int> res(n, 0);
        
        stack<int> stk;
        for (const string &l : logs) {
            vector<string> curr_log = split(l, ':');
            int fid = stoi(curr_log[0]);
            string status = curr_log[1];
            int timestamp = stoi(curr_log[2]);
            
            if (status == "start") {
                if (!stk.empty()) {
                    res[stk.top()] += timestamp - last_timestamp_;
                }
                
                stk.push(fid);
            } else {
                res[stk.top()] += ++timestamp - last_timestamp_;
                stk.pop();
            }
            
            last_timestamp_ = timestamp;
        }
        
        return res;
    }
    
  private:
    int last_timestamp_ = 0;
    
  private:
    vector<string> split(const string &s, char delim) {
        vector<string> res;
        
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            res.push_back(item);
        }
        
        return res;
    }
};
