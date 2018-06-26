/*
13. Implement strStr()
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Clarification
Do I need to implement KMP Algorithm in a real interview?
Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your 
basic implementation ability. But make sure you confirm with the interviewer first.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n^2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)


Author: Yuan Li
Date: 6/25/2018 
Difficulty: Easy
*/

class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source == nullptr || target == nullptr) {
            return -1;
        }
        
        if (*target == '\0') {
            return 0;
        }
        
        int n_source = strlen(source);
        int n_target = strlen(target);
        
        if (n_source >= n_target) {
            for (int i = 0; i < n_source - n_target + 1; i++) {
                if (source[i] == target[0]) {
                    int j = 1;
                    for (; j < n_target; j++) {
                        if (source[i+j] != target[j]) {
                            break;
                        }
                    }
                    
                    if (j == n_target) {
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
};
