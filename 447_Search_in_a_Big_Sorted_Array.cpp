/*
447. Search in a Big Sorted Array
Given a big sorted array with positive integers sorted by ascending order. The array is so big so that you can not get the length of the whole array directly, and you can only access the kth number by ArrayReader.get(k) (or ArrayReader->get(k) for C++). Find the first index of a target number. Your algorithm should be in O(log k), where k is the first index of the target number.

Return -1, if the number doesn't exist in the array.

If you accessed an inaccessible index (outside of the array), ArrayReader.get will return 2,147,483,647.

Example
Given [1, 3, 6, 9, 21, ...], and target = 3, return 1.

Given [1, 3, 6, 9, 21, ...], and target = 4, return -1.

Challenge
O(log k), k is the first index of the given target number.


Author: Yuan Li
Date: 6/29/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        int index = 1;
        while (reader->get(index-1) < target) {
            index *= 2;
        }
        
        int start = 0, end = index - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (reader->get(mid) == target) {
                end = mid;
            } else if (reader->get(mid) < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (reader->get(start) == target)
            return start;
        if (reader->get(end) == target) 
            return end;
        return -1;
    }
};
