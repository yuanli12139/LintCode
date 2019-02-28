/*
528. Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example
Example1

Input: list = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]

Example2

Input: list = [1,[4,[6]]]
Output: [1,4,6]

Notice
You don't need to implement the remove method.


Author: Yuan Li
Date: 2/27/2019 
Difficulty: Medium
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        has_next_ = false;
        
        vector<NestedInteger>::reverse_iterator rit = nestedList.rbegin();
        for (; rit != nestedList.rend(); ++rit) {
            stk_.push(*rit);
        }
    }
 
    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        if (!has_next_) {
            hasNext();    
        }
        has_next_ = false;
        return next_elem_;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        if (has_next_) {
            return true;
        }
        
        while (!stk_.empty()) {
            NestedInteger top = stk_.top();
            stk_.pop();
            if (top.isInteger()) {
                has_next_ = true;
                next_elem_ = top.getInteger();
                return true;
            }
            
            vector<NestedInteger> top_list = top.getList();
            vector<NestedInteger>::reverse_iterator rit = top_list.rbegin();
            for (; rit != top_list.rend(); ++rit) {
                stk_.push(*rit);
            }
        }
        
        return false;
    }
    
  private:
    stack<NestedInteger> stk_;
    bool has_next_;
    int next_elem_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */

