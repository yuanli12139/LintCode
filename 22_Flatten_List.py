#!/usr/bin/python3

'''
22. Flatten List

Given a list, each element in the list can be a list or integer. flatten it into a simply list with integers.

Example
Example 1:
	Input:  [[1,1],2,[1,1]]
	Output: [1,1,2,1,1]
	
	Explanation:
	flatten it into a simply list with integers.

Example 2:
	Input:  [1,2,[1,2]]
	Output:[1,2,1,2]
	
	Explanation:  
	flatten it into a simply list with integers.

Example 3:
	Input: [4,[3,[2,[1]]]]
	Output:[4,3,2,1]
	
	Explanation: 
	flatten it into a simply list with integers.

Challenge
Do it in non-recursive.

Notice
If the element in the given list is a list, it can contain list too.

Author: Yuan Li
Date: 2/26/2019 
Difficulty: Easy
'''

class Solution(object):

    # @param nestedList a list, each element in the list 
    # can be a list or integer, for example [1,2,[1,2]]
    # @return {int[]} a list of integer
    def flatten(self, nestedList):
        # Write your code here
        stk = [nestedList]
        
        res = []
        while stk:
            top = stk.pop()
            if isinstance(top, list):
                for item in top:
                    stk.append(item)
            else:
                res.append(top)
                
        return res[::-1]

