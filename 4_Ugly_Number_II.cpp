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

// priority queue - O(nlogn)
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


// 3 pointers - O(n)
class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        long lastNum = 1;
        vector<long> uglyNums = {lastNum};
        int p2 = 0, p3 = 0, p5 = 0;
        
        while (n-- > 1) {
            lastNum = uglyNums.back();
            
            if (uglyNums[p2] * 2 == lastNum) p2++;
            if (uglyNums[p3] * 3 == lastNum) p3++;
            if (uglyNums[p5] * 5 == lastNum) p5++;
            
            long minUglyNum = min(min(uglyNums[p2] * 2, uglyNums[p3] * 3), uglyNums[p5] * 5);
            uglyNums.push_back(minUglyNum);
        }
        
        return uglyNums.back();
    }
};
