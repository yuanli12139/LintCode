/*
149. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example
Given array [3,2,3,1,2], return 1.


Author: Yuan Li
Date: 7/30/2018 
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int res = 0;
        
        if (prices.empty()) {
            return res;
        }
        
        int last_min = INT_MAX;
        for (auto p : prices) {
            res = p - last_min > res ? p - last_min : res;
            last_min = p < last_min ? p : last_min;
        }
        
        return res;
    }
};
