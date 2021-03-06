#!/usr/bin/python3

'''
228. Middle of Linked List
Find the middle node of a linked list.

Example
Given 1->2->3, return the node with value 2.

Given 1->2, return the node with value 1.

Challenge
If the linked list is in a data stream, can you find the middle without iterating the linked list again?


Author: Yuan Li
Date: 6/10/2018 
Difficulty: Naive
'''

"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""


class Solution:
    """
    @param: head: the head of linked list.
    @return: a middle node of the linked list
    """
    def middleNode(self, head):
        # write your code here
        if head == None:
            return None
        
        slow = head
        fast = head.next
        
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next
            
        return slow
       