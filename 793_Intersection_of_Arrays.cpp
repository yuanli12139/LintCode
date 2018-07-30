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


// priority queue - O(knlog(n) + nklog(k))
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
        
        auto comp = [](const pair<int, pair<int, int>> &lhs, const pair<int, pair<int, int>> &rhs) {
            return lhs.first > rhs.first;    
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> pq(comp);
        
        for (int i = 0; i < arrs.size(); ++i) {
            if (arrs[i].empty()) {
                return res;
            }
            
            sort(arrs[i].begin(), arrs[i].end());
            
            pair<int, pair<int, int>> head(arrs[i][0], pair<int, int>(i, 0));
            pq.push(head);
        }
        
        int cnt = 0, last;
        while (!pq.empty()) {
            if (cnt == 0) {
                last = pq.top().first;
            }
            
            if (pq.top().first != last) {
                last = pq.top().first;
                cnt = 0;
            }
            
            cnt++;

            if (cnt == arrs.size()) {
                res++;
                cnt = 0;
            }
            
            int next_i = pq.top().second.first;
            int next_j = pq.top().second.second + 1;
            if (next_j < arrs[next_i].size()) {
                pair<int, pair<int, int>> next(arrs[next_i][next_j], pair<int, int>(next_i, next_j));
                pq.push(next);
            }
            
            pq.pop();
        }
    
        return res;
    }
};
