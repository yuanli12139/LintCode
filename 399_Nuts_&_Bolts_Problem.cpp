/*
399. Nuts & Bolts Problem

Given a set of n nuts of different sizes and n bolts of different sizes. There is a one-one mapping between nuts and bolts.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller. We will give you a compare function to compare nut with bolt.

Using the function we give you, you are supposed to sort nuts or bolts, so that they can map in order.

Example
Given nuts = ['ab','bc','dd','gg'], bolts = ['AB','GG', 'DD', 'BC'].

Your code should find the matching of bolts and nuts.

According to the function, one of the possible return:

nuts = ['ab','bc','dd','gg'], bolts = ['AB','BC','DD','GG'].

If we give you another compare function, the possible return is the following:

nuts = ['ab','bc','dd','gg'], bolts = ['BC','AA','DD','GG'].

So you must use the compare function that we give to do the sorting.

The order of the nuts or bolts does not matter. You just need to find the matching bolt for each nut.


Author: Yuan Li
Date: 2/25/2019 
Difficulty: Medium
*/

/**
 * class Comparator {
 *    public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
  public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        quickSort(nuts, bolts, 0, nuts.size() - 1, compare);
    }
    
  private:
    void quickSort(vector<string> &nuts, vector<string> &bolts, int start, int end, Comparator &compare) {
        if (start >= end) {
            return;
        }
        
        int pivot_id = partition(bolts, start, end, nuts[start], compare);
        partition(nuts, start, end, bolts[pivot_id], compare);
        
        quickSort(nuts, bolts, start, pivot_id - 1, compare);
        quickSort(nuts, bolts, pivot_id + 1, end, compare);
    }
    
    int partition(vector<string> &arr, int start, int end, const string &pivot, Comparator &compare) {
        int left = start, right = end;
        
        // find pivot pos
        for (int i = start; i <= end; ++i) {
            if (compare.cmp(arr[i], pivot) == 0 || compare.cmp(pivot, arr[i]) == 0) {
                swap(arr[start], arr[i]);
                ++left;
                break;
            }
        }
        
        // partition arr w/o pivot
        while (left <= right) {
            while (left <= right && (compare.cmp(arr[left], pivot) == -1 || compare.cmp(pivot, arr[left]) == 1)) {
                ++left;
            }
            while (left <= right && (compare.cmp(arr[right], pivot) == 1 || compare.cmp(pivot, arr[right]) == -1)) {
                --right;
            }
            
            if (left <= right) {
                swap(arr[left++], arr[right--]);
            }
        }
        
        // put pivot back in place
        swap(arr[start], arr[right]);
        
        return right;
    }
};

