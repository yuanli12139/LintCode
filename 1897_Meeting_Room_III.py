#!/usr/bin/python3

'''
1897. Meeting Room III
you have a list intervals of current meetings, and some meeting rooms with start and end timestamp.When a stream of new meeting ask coming in, check if it can be scheduled.A meeting room can only hold one meeting at a time. Each inquiry is independent.

Example 1:
Input:
Intervals:[[1,2],[4,5],[8,10]], rooms = 1, ask: [[2,3],[3,4]]
Output: [true,true]
Explanation:
For the ask of [2,3], we can arrange a meeting room room0.
The following is the meeting list of room0:
[[1,2], [2,3], [4,5], [8,10]]
For the ask of [3,4], we can arrange a meeting room room0.
The following is the meeting list of room0:
[[1,2], [3,4], [4,5], [8,10]]

Example 2:
Input:
[[1,2],[4,5],[8,10]]
1
[[4,5],[5,6]]
Output:
[false,true]

Notice
Ensure that Intervals can be arranged in rooms meeting rooms
Ensure that the end time of any meeting is not greater than 50000
|Intervals|<=50000
|ask|<=50000
rooms<=20


Author: Yuan Li
Date: 11/29/2020
Difficulty: Medium
'''

cclass Solution:
    """
    @param intervals: the intervals
    @param rooms: the sum of rooms
    @param ask: the ask
    @return: true or false of each meeting
    """
    def meetingRoomIII(self, intervals, rooms, ask):
        # Write your code here.
        # intervals.sort(key=lambda x: x[0])
        
        occupied = [0] * 50001
        for intv in intervals:
            occupied[intv[0]] += 1
            occupied[intv[1]] -= 1

        for i in range(1, len(occupied)):
            occupied[i] += occupied[i-1]
           
        conflicts = [False]    
        for i in range(1, len(occupied)):
            conflicts.append(occupied[i] == rooms)
            
        for i in range(1, len(conflicts)):
            conflicts[i] += conflicts[i-1]
            
        res = []
        for intv in ask:
            res.append(conflicts[intv[1]-1] - conflicts[intv[0]-1] == False)
        
        return res
