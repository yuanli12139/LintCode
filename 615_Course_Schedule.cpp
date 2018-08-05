/*
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
Date: 8/4/2018 
Difficulty: Medium
*/

class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here
        // calculate in-degree
        unordered_map<int, unordered_set<int>> nextCourses;
        for (auto p : prerequisites) {
            nextCourses[p.second].insert(p.first);
        }
        
        vector<int> inDegree(numCourses, 0);
        for (auto c : nextCourses) {
            for (auto nc : c.second) {
                inDegree[nc]++;
            }   
        }
        
        // put all courses with 0 in-degree into queue
        queue<int> courseQ;
        for (int c = 0; c < numCourses; ++c) {
            if (inDegree[c] == 0) {
                courseQ.push(c);
            }
        }
        
        // decrease in-degree and add new courses with 0 in-degree in queue
        int count = 0;
        while (!courseQ.empty()) {
            int c = courseQ.front();
            courseQ.pop();
            count++;
            
            if (!nextCourses.count(c)) {
                continue;    
            }
            
            for (nc : nextCourses[c]) {
                inDegree[nc]--;
                if (inDegree[nc] == 0) {
                    courseQ.push(nc);
                }
            }
        }
        
        return count == numCourses;
    }
};
