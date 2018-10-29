#!/usr/bin/python3

'''
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
Date: 10/28/2018 
Difficulty: Easy
'''

#!/usr/bin/python2
class Solution:
    """
    @param logs: the logs
    @return: the log after sorting
    """
    def logSort(self, logs):
        # Write your code here
        return sorted(logs, cmp=self.comp)
        
    def comp(self, log1, log2):
        log_id1, content1 = log1.split(" ", 1)
        log_id2, content2 = log2.split(" ", 1)
        type1 = self.getType(content1)
        type2 = self.getType(content2)
        
        if type1 == 1 and type2 == 1:
            if content1 < content2:
                return -1
            if content1 > content2:
                return 1

            if log_id1 < log_id2:
                return -1
            return 1
        
        if type1 < type2:
            return -1
        return 1
        
    def getType(self, content):
        if content[0].isalpha():
            return 1
        return 2

