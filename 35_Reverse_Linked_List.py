#!/usr/bin/python3

'''
35. Reverse Linked List
Reverse a linked list.

Example
For linked list 1->2->3, the reversed linked list is 3->2->1

Challenge
Reverse it in-place and in one-pass


Author: Yuan Li
Date: 8/13/2018 
Difficulty: Easy
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
    @param head: n
    @return: The new head of reversed linked list.
    """
    def reverse(self, head):
        # write your code here
        if head == None:
            return head
        
        i = head
        j = head.next
        while j != None:
            temp = j
            j = j.next
            temp.next = i
            
            if i == head:
                i.next = None
            
            i = temp
        
        return i
