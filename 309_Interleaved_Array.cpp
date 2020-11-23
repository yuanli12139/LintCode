/*
309. Interleaved Array
Given two arrays of the same length, interleave them by taking the first element of the first one, the first element of the second one, the second element of the first array and so on for all element of the arrays. Return the new interleaved array.
Hint : the length ≤ 10000

Example
Input: 
[1,2]
[3,4]
Output: 
[1,3,2,4]


Author: Yuan Li
Date: 11/22/2020 
Difficulty: Easy
*/

class Solution {
public:
    /**
     * @param A: the array A
     * @param B: the array B
     * @return: returns an alternate array of arrays A and B.
     */
    vector<int> interleavedArray(vector<int> &A, vector<int> &B) {
        // Interleaved Array
        vector<int> C;
        for (int i = 0; i < A.size(); ++i) {
            C.push_back(A[i]);
            C.push_back(B[i]);
        }
        
        return C; 
    }
};
