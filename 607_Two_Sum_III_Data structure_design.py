#!/usr/bin/python3

'''
607. Two Sum III - Data structure design
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example
add(1); add(3); add(5);
find(4) // return true
find(7) // return false


Author: Yuan Li
Date: 6/13/2018 
Difficulty: Easy
'''

class TwoSum:
    nums = []
    
    """
    @param: number: An integer
    @return: nothing
    """
    def add(self, number):
        # write your code here
        self.nums.append(number)

    """
    @param: value: An integer
    @return: Find if there exists any pair of numbers which sum is equal to the value.
    """
    def find(self, value):
        # write your code here
        hashTable = {}
        for num in self.nums:
            if value - num in hashTable:
                return True
            hashTable[num] = num
                
        return False

        