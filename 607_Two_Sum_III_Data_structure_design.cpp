/*
607. Two Sum III - Data structure design
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example
add(1); add(3); add(5);
find(4) // return true
find(7) // return false


Author: Yuan Li
Date: 6/26/2018 
Difficulty: Easy
*/

class TwoSum {
public:
    vector<int> nums;
    
    /*
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        nums.push_back(number);
    }

    /*
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        unordered_set<int> s;
        for (auto num : nums) {
            if (s.find(value - num) != s.end())
                return true;
                
            s.insert(num);
        }
        
        return false;
    }
};
