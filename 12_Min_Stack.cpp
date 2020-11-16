/*
12. Min Stack
Implement a stack with min() function, which will return the smallest number in the stack.

It should support push, pop and min operation all in O(1) cost.

Example
push(1)
pop()   // return 1
push(2)
push(3)
min()   // return 2
push(1)
min()   // return 1
Notice
min operation will never be called if there is no number in the stack.


Author: Yuan Li
Date: 11/14/2018 
Difficulty: Medium
*/

class MinStack {
  public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        stk_.push(number);
        
        if (min_stk_.empty()) {
            min_stk_.push(number);
        } else {
            min_stk_.push(std::min(min_stk_.top(), number));
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int res = stk_.top();
        
        stk_.pop();
        min_stk_.pop();
        
        return res;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        return min_stk_.top();
    }
    
  private:
    stack<int> stk_;
    stack<int> min_stk_; // save current min
};

