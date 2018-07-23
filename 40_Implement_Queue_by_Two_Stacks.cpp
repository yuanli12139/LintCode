/*
40. Implement Queue by Two Stacks
As the title described, you should only use two stacks to implement a queue's actions.

The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.

Both pop and top methods should return the value of first element.

Example
push(1)
pop()     // return 1
push(2)
push(3)
top()     // return 2
pop()     // return 2

Challenge
implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.


Author: Yuan Li
Date: 7/22/2018 
Difficulty: Medium
*/

class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        stack1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int item;
        
        if (!stack2.empty()) {
            item = stack2.top();
            stack2.pop();
            return item;
        }
        
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        if (!stack2.empty()) {
            item = stack2.top();
            stack2.pop();
        }
        
        return item;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        int item;
        
        if (!stack2.empty()) {
            item = stack2.top();
            return item;
        }
        
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        if (!stack2.empty()) {
            item = stack2.top();
        }
        
        return item;
    }
    
private:
    stack<int> stack1;
    stack<int> stack2;
};
