/*
1117. Smallest Range
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

Example
Example 1:

Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Notice
the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.

Reference
https://www.youtube.com/watch?time_continue=17&v=csJXQZFYklE


Author: Yuan Li
Date: 9/4/2018 
Difficulty: Hard
*/

// O(n * k * log(k))
class Solution {
  public:
    /**
     * @param nums: k lists of sorted integers
     * @return: the smallest range that includes at least one number from each of the k lists
     */
    vector<int> smallestRange(vector<vector<int>> &nums) {
        // write your code here
        vector<int> pos(nums.size(), 0);
        
        auto comp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
        return lhs.first > rhs.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_pq(comp);
        
        int max_num = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            min_pq.push({nums[i][0], i});
            max_num = max(max_num, nums[i][0]);
        }
        
        vector<int> res;
        int min_range = INT_MAX;
        while (1) {
            pair<int, int> min_pair = min_pq.top();
            min_pq.pop();
            
            int min_num = min_pair.first;
            if (max_num - min_num < min_range) {
                res = {min_num, max_num};
                min_range = max_num - min_num;
            }
            
            int i = min_pair.second;
            int j = ++pos[i];
            if (j >= nums[i].size()) {
                break;
            }
            
            int next_num = nums[i][j];
            max_num = max(max_num, next_num);
            min_pq.push({next_num, i});
        }
        
        return res;
    }
};
