/*
6. Merge Two Sorted Arrays
Merge two given sorted integer array A and B into a new sorted integer array.

Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]

Challenge
How can you optimize your algorithm if one array is very large and the other is very small?


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> res;
        
        if (A.empty()) {
            return B;
        }
        
        if (B.empty()) {
            return A;
        }
        
        int i = 0, j = 0;
        res.reserve(A.size() + B.size());

        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j]) {
                res.push_back(A[i]);
                i++;
            } else {
                res.push_back(B[j]);
                j++;
            }
        }
        
        if (i < A.size()) {
            res.insert(res.end(), A.begin() + i, A.end());
        }

        if (j < B.size()) {
            res.insert(res.end(), B.begin() + j, B.end());
        }
        
        return res;
    }
};
