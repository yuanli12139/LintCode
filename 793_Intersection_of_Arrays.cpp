/*
793. Intersection of Arrays
Give a number of arrays, find their intersection, and output their intersection size.

The total number of all array elements is not more than 500000.
There are no duplicated elements in each array.

Example
Given [[1,2,3],[3,4,5],[3,9,10]], return 1

explanation:
Only element 3 appears in all arrays, the intersection is [3], and the size is 1.
Given [[1,2,3,4],[1,2,5,6,7][9,10,1,5,2,3]], return 2

explanation:
Only element 1,2 appear in all arrays, the intersection is [1,2], the size is 2.


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Medium
*/

// hash map - O(nk)
class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here
        int res = 0;
        
        if (arrs.empty()) {
            return res;
        }
        
        unordered_map<int, int> num2cnt;
        for (auto &arr : arrs) {
            for (int n : arr) {
                if (!num2cnt.count(n)) {
                    num2cnt[n] = 1;
                } else {
                    num2cnt[n]++;
                }
            }
        }
        
        for (auto &entry : num2cnt) {
            if (entry.second == arrs.size()) {
                res++;
            }
        }
        
        return res;
    }
};
