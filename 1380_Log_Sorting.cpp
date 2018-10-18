/*
1380. Log Sorting
Give a log, consisting of List< String >, each element representing one line of logs. Each line of log information is separated by a space. The first is the ID of the log, followed by the log content.
There are two ways to make content:

All consist of letters and spaces.
All consist of numbers and spaces.
Now that the logs are sorted, it is required that component 1 be sorted in order of content lexicography and placed at the top, and component 2 should be placed at the bottom and output in the order of input. (Note that the space also belongs to the content, and when the lexicographic order of the composition method 1 is equal, sort according to the dictionary order of log ID., and the guarantee ID is not repeated)

Example
Given

[
    "zo4 4 7",
    "a100 Act zoo",
    "a1 9 2 3 1",
    "g9 act car"
]
, return

[
    "a100 Act zoo",
    "g9 act car",
    "zo4 4 7",
    "a1 9 2 3 1"
]
Explanation:
"Act zoo" < "act car", So the output is as above.
Given

[
    "zo4 4 7",
    "a100 Actzoo",
    "a100 Act zoo",
    "Tac Bctzoo",
    "Tab Bctzoo",
    "g9 act car"
]
, return

[
    "a100 Act zoo",
    "a100 Actzoo",
    "Tab Bctzoo",
    "Tac Bctzoo",
    "g9 act car",
    "zo4 4 7"
]
Explanation:
Because "Bctzoo" == "Bctzoo", the comparison "Tab" and "Tac" have "Tab" < Tac ", so" Tab Bctzoo "< Tac Bctzoo".
Because ' '<'z', so "A100 Act zoo" < A100 Actzoo".
Notice
The total number of logs entered was n, and n < = 10000.

The length of each line is mi, and mi < = 100.


Author: Yuan Li
Date: 10/17/2018 
Difficulty: Easy
*/

class Solution {
  public:
    /**
     * @param logs: the logs
     * @return: the log after sorting
     */
    vector<string> logSort(vector<string> &logs) {
        // Write your code here
        vector<Log> logs2;
        for (int i = 0; i < logs.size(); ++i) {
            int j = 0;
            for (; j < logs[i].length(); ++j) {
                if (logs[i][j] == ' ') {
                    break;
                }
            }
            
            Log l2;
            l2.index = i;
            l2.type = 1;
            l2.log_id = logs[i].substr(0, j);
            l2.content = logs[i].substr(j + 1);
            if (isdigit(l2.content[0])) {
                l2.type = 2;
            }

            logs2.push_back(l2);
        }
        
        sort(logs2.begin(), logs2.end());
        
        vector<string> res;
        for (auto l2 : logs2) {
            res.push_back(l2.log_id + ' ' + l2.content);
        }
        
        return res;
    }
    
  private:
    struct Log {
        int index;
        int type;
        string log_id;
        string content;
        
        friend bool operator< (const Log &lhs, const Log &rhs) {
            if (lhs.type == 1 && rhs.type == 1) {
                if (lhs.content == rhs.content) {
                    return lhs.log_id < rhs.log_id;
                }
                return lhs.content < rhs.content; 
            }
            
            if (lhs.type == 2 && rhs.type == 2) {
                return lhs.index < rhs.index;
            }
            
            return lhs.type < rhs.type;
        }
    };
};

