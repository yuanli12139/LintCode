/*
130. Heapify
Given an integer array, heapify it into a min-heap array.

For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

Example
Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.

Challenge
O(n) time complexity


Author: Yuan Li
Date: 7/23/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
        // start from the parent closest to leaf
        for (int i = (A.size() - 1) / 2; i >= 0; --i) {
            siftdown(A, i);
        }
    }
    
    void siftdown(vector<int> &A, int k) {
        while (k * 2 + 1 < A.size()) { // siftdown till no son
            int left_son = k * 2 + 1; // left son index
            int right_son = k * 2 + 2; // right son index
            
            int smaller_son;
            if (right_son < A.size() && A[right_son] < A[left_son]) {
                smaller_son = right_son;
            } else {
                smaller_son = left_son;
            }
            
            if (A[smaller_son] >= A[k]) { // son must be no smaller than parent
                break;
            }
            
            int temp = A[smaller_son];
            A[smaller_son] = A[k];
            A[k] = temp;
            k = smaller_son;
        }
    }
};
