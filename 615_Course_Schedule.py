#!/usr/bin/python3

'''
615. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example
Given n = 2, prerequisites = [[1,0]]
Return true

Given n = 2, prerequisites = [[1,0],[0,1]]
Return false


Author: Yuan Li
Date: 6/24/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param: numCourses: a total of n courses
    @param: prerequisites: a list of prerequisite pairs
    @return: true if can finish all courses or false
    """
    def canFinish(self, numCourses, prerequisites):
        # write your code here
        # calculate in-degree
        next_courses = {}
        for p in prerequisites:
            if p[1] not in next_courses:
                next_courses[p[1]] = set([p[0]])
            else:
                next_courses[p[1]].add(p[0])
                
        in_degree = {i: 0 for i in range(numCourses)}
        for c in next_courses:
            for nc in next_courses[c]:
                in_degree[nc] += 1
            
        # put courses with in-degree = 0 in queue:
        queue = []
        for i in range(numCourses):
            if in_degree[i] == 0:
                queue.append(i)
                
        # decrease in-degree and add new courses with in-degree = 0
        count = 0
        while queue:
            curr_course = queue.pop(0)
            count += 1
            
            if curr_course in next_courses:
                for c in next_courses[curr_course]:
                    in_degree[c] -= 1
                    
                    if in_degree[c] == 0:
                        queue.append(c)
          
        return count == numCourses
        