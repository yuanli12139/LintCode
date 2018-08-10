#!/usr/bin/python3

'''
642. Moving Average from Data Stream
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example
MovingAverage m = new MovingAverage(3);
m.next(1) = 1 // return 1.00000
m.next(10) = (1 + 10) / 2 // return 5.50000
m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
m.next(5) = (10 + 3 + 5) / 3 // return 6.00000


Author: Yuan Li
Date: 8/9/2018 
Difficulty: Easy
'''

class MovingAverage:
    """
    @param: size: An integer
    """
    def __init__(self, size):
        # do intialization if necessary
        self.size = size
        self.q = []
        self.s = 0
        
    """
    @param: val: An integer
    @return:  
    """
    def next(self, val):
        # write your code here
        if len(self.q) == self.size:
            self.s -= self.q[0]
            self.q.pop(0)
        
        self.s += val
        self.q.append(val)
        
        return self.s / len(self.q)

# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param = obj.next(val)
