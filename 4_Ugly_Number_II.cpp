/*
4. Ugly Number II
Ugly number is a number that only have factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Note that 1 is typically treated as an ugly number.

Example
If n=9, return 10.

Challenge
O(n log n) or O(n) time.


Author: Yuan Li
Date: 7/25/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        long res;
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> in_pq;
        
        pq.push(1);
        in_pq.insert(1);
        
        while (n-- > 0) {
            res = pq.top();
            pq.pop();
            
            for (int i : {2, 3, 5}) {
                if (in_pq.count(res * i)) {
                    continue;
                }
                
                pq.push(res * i);
                in_pq.insert(res * i);
            }
        }
        
        return res;
    }
};
