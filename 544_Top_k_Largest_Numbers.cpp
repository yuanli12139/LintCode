/*
544. Top k Largest Numbers
Given an integer array, find the top k largest numbers in it.

Example
Given [3,10,1000,-99,4,100] and k = 3.
Return [1000, 100, 10].


Author: Yuan Li
Date: 7/26/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        
        // min-heap to knock out nums smaller than top k largest
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for (int &n : nums) {
            if (pq.size() < k) {
                pq.push(n);
                continue;
            }
            
            if (n > pq.top()) {
                pq.pop();
                pq.push(n);
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
