/*
494. Implement Stack by Two Queues
Implement a stack by two queues. The queue is first in first out (FIFO). That means you can not directly pop the last element in a queue.

Example
push(1)
pop()
push(2)
isEmpty() // return false
top() // return 2
pop()
isEmpty() // return true


Author: Yuan Li
Date: 7/22/2018 
Difficulty: Easy
*/

class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        // write your code here
        queue1.push(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        // write your code here
        if (queue1.empty()) {
            return;
        }
        
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        
        queue1.pop();
        swap(queue1, queue2);
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        int item;
        while (!queue1.empty()) {
            item = queue1.front();
            queue2.push(item);
            queue1.pop();
        }
        
        swap(queue1, queue2);
        return item;
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        // write your code here
        return queue1.empty();
    }
    
private:
    queue<int> queue1;
    queue<int> queue2;
    
    inline void swap(queue<int> &queue1, queue<int> &queue2) {
        queue<int> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }
};
