/*
64. Merge Sorted Array
Given two sorted integer arrays A and B, merge B into A as one sorted array.

You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Example
A = [1, 2, 3, empty, empty], B = [4, 5]

After merge, A will be filled as [1, 2, 3, 4, 5]


Author: Yuan Li
Date: 7/29/2018 
Difficulty: Easy
*/

class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int i = m - 1, j = n - 1, back = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[back--] = A[i--];
            } else {
                A[back--] = B[j--];
            }
        }
        
        if (j >= 0) {
            memcpy(A, B, (j+1)*sizeof(int)); // j+1 elements in B remain unmerged
        }
    }
};
