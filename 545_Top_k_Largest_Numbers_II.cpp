/*
545. Top k Largest Numbers II
Implement a data structure, provide two interfaces:

add(number). Add a new number in the data structure.
topk(). Return the top k largest numbers in this data structure. k is given when we create the data structure.

Example
s = new Solution(3);
>> create a new data structure.
s.add(3)
s.add(10)
s.topk()
>> return [10, 3]
s.add(1000)
s.add(-99)
s.topk()
>> return [1000, 10, 3]
s.add(4)
s.topk()
>> return [1000, 10, 4]
s.add(100)
s.topk()
>> return [1000, 100, 10]


Author: Yuan Li
Date: 7/26/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
    * @param k: An integer
    */
    Solution(int k) {
        // do intialization if necessary
        this->k = k;
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        if (pq.size() < k) {
            pq.push(num);
            return;
        }
        
        if (num > pq.top()) {
            pq.pop();
            pq.push(num);
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        for (auto n : res) {
            pq.push(n);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    priority_queue<int, vector<int>, greater<int> > pq; // min-heap to only keep k largest
    int k;
};
