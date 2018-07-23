/*
955. Implement Queue by Circular Array
Implement queue by circulant array. You need to support the following methods:

CircularQueue(n): initialize a circular array with size n to store elements
boolean isFull(): return true if the array is full
boolean isEmpty(): return true if there is no element in the array
void enqueue(element): add an element to the queue
int dequeue(): pop an element from the queue

it's guaranteed in the test cases we won't call enqueue if it's full and we also won't call dequeue if it's empty. So it's ok to raise exception in scenarios described above.

Example
CircularQueue(5)
isFull()   => false
isEmpty() => true
enqueue(1)
dequeue()  => 1


Author: Yuan Li
Date: 7/22/2018 
Difficulty: Medium
*/

class CircularQueue {
public:
    CircularQueue(int n) {
        // do intialization if necessary
        circularArray.resize(n);
        // circularArray.reserve(n) will allocate space without filling it
        
        front = 0;
        rear = 0;
        size = 0;
    }
    
    /**
     * @return:  return true if the array is full
     */
    bool isFull() {
        // write your code here
        return size == circularArray.size(); 
    }

    /**
     * @return: return true if there is no element in the array
     */
    bool isEmpty() {
        // write your code here
        return size == 0;
    }

    /**
     * @param element: the element given to be added
     * @return: nothing
     */
    void enqueue(int element) {
        // write your code here
        circularArray[rear] = element;
        rear = (rear + 1) % circularArray.size();
        size++;
    }

    /**
     * @return: pop an element from the queue
     */
    int dequeue() {
        // write your code here
        int item = circularArray[front];
        front = (front + 1) % circularArray.size();
        size--;
        
        return item;
    }
    
private:
    vector<int> circularArray;
    int front;
    int rear;
    int size;
};
