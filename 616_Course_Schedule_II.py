#!/usr/bin/python3

'''
616. Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example
Given n = 2, prerequisites = [[1,0]]
Return [0,1]

Given n = 4, prerequisites = [1,0],[2,0],[3,1],[3,2]]
Return [0,1,2,3] or [0,2,1,3]

Author: Yuan Li
Date: 6/24/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param: numCourses: a total of n courses
    @param: prerequisites: a list of prerequisite pairs
    @return: the course order
    """
    def findOrder(self, numCourses, prerequisites):
        # write your code here
        # calculate in-degree
        next_courses = {}
        for p in prerequisites:
            if p[1] not in next_courses:
                next_courses[p[1]] = set([p[0]])
            else:
                next_courses[p[1]].add(p[0])
                
        in_degrees = {i: 0 for i in range(numCourses)}
        for c in next_courses:
            for nc in next_courses[c]:
                in_degrees[nc] += 1
                
        # add courses with 0 in-degree into queue
        queue = []
        for i in in_degrees:
            if in_degrees[i] == 0:
                queue.append(i)
                
        # decrease in-degree and add new courses with 0 in-degree
        order = []
        count = 0
        while queue:
            curr_course = queue.pop(0)
            order.append(curr_course)
            count += 1
            
            if curr_course in next_courses:
                for nc in next_courses[curr_course]:
                    in_degrees[nc] -= 1
                    if in_degrees[nc] == 0:
                        queue.append(nc)
                    
        if count == numCourses:
            return order
        return []
                