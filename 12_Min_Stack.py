#!/usr/bin/python3

'''
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
Date: 8/11/2018 
Difficulty: Medium
'''

class MinStack:
    
    def __init__(self):
        # do intialization if necessary
        self.stack0 = []
        self.stack1 = []
        self.last_pushed = []
        
    """
    @param: number: An integer
    @return: nothing
    """
    def push(self, number):
        # write your code here
        if not self.stack0 or self.stack0[-1] >= number:
            self.stack0.append(number)
            self.last_pushed.append(0)
            
        else:
            self.stack1.append(number)
            self.last_pushed.append(1)

    """
    @return: An integer
    """
    def pop(self):
        # write your code here
        last_stack = self.last_pushed.pop()
        if last_stack == 0:
            return self.stack0.pop()
            
        return self.stack1.pop()

    """
    @return: An integer
    """
    def min(self):
        # write your code here
        return self.stack0[-1]
