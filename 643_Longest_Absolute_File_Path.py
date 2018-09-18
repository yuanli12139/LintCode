#!/usr/bin/python3

'''
643. Longest Absolute File Path
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext        
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
            
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Example
Give input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" return 20

Notice
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.
Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.


Author: Yuan Li
Date: 9/17/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param input: an abstract file system
    @return: return the length of the longest absolute path to file
    """
    def lengthLongestPath(self, input):
        # write your code here
        res = 0
        
        if not input:
            return res

        len_sum = [0 for _ in range(len(input) + 1)]
        
        for d in input.split('\n'):
            level = d.rfind('\t') + 2 # count how many '\t', level starts from 1
            d_len = len(d) - (level - 1)
            if '.' in d:
                res = max(res, len_sum[level-1] + d_len)
            else:
                len_sum[level] = len_sum[level-1] + d_len + 1 # don't miss '/'
                
        return res

