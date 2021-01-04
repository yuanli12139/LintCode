/*
1601. Boats to Save People
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person. (It is guaranteed each person can be carried by a boat.)

Example
Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)

Notice
1 <= people.length <= 500001 <= people.length <= 50000
1 <= people[i] <= limit <= 300001 <= people[i] <= limit <= 30000


Author: Yuan Li
Date: 1/3/2021
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param people: The i-th person has weight people[i].
     * @param limit: Each boat can carry a maximum weight of limit.
     * @return: Return the minimum number of boats to carry every given person. 
     */
    int numRescueBoats(vector<int> &people, int limit) {
        // Write your code here.
        int res = 0;
        
        if (people.empty()) {
            return res;
        }
        
        sort(people.begin(), people.end());
        
        int left = 0, right = people.size() - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                res++;
                left++;
                right--;
            } else {
                res++;
                right--;
            }
        }

        return res;
    }
};
