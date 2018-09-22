/*
543. Kth Largest in N Arrays
Find K-th largest element in N arrays.

Example
In n=2 arrays [[9,3,2,4,7],[1,2,3,4,8]], the 3rd largest element is 7.

In n=2 arrays [[9,3,2,4,8],[1,2,3,4,2]], the 1st largest element is 9, 2nd largest element is 8, 3rd largest element is 7 and etc.

Notice
You can swap elements in the array


Author: Yuan Li
Date: 9/21/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        // write your code here
        // sort each array in descending order
        for (auto &arr : arrays) {
            if (!arr.empty()) {
                sort(arr.begin(), arr.end(), greater<int>());
            }
        }
        
        // max heap
        // auto comp = [](const tuple<int, int, int> &lhs, const tuple<int, int, int> &rhs) {
        //     return get<0>(lhs) < get<0>(rhs);    
        // };
        // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp);
        priority_queue<tuple<int, int, int>> pq;
        
        for (int i = 0; i < arrays.size(); ++i) {
            if (!arrays[i].empty()) {
                pq.push(make_tuple(arrays[i][0], i, 0));
            }
        }
        
        tuple<int, int, int> k_max;
        while (k-- > 0) {
            k_max = pq.top();
            pq.pop();
            
            int i = get<1>(k_max), j = get<2>(k_max);
            if (j + 1 < arrays[i].size()) {
                pq.push(make_tuple(arrays[i][j+1], i, j+1));
            }
        }
        
        return get<0>(k_max);
    }
};
