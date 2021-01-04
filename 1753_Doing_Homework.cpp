/*
1753. Doing Homework
For n people, each of them needs to do m jobs independently.
The i job takes cost[i] time. Since each person's free time is different, the i person has val[i] time, which means that the total time for his jobs will not exceed val[i]. Everyone starts with the first job, then the 2nd, the 3rd... Now, you need to figure out how much time they spend.

Example
Example 1:

Given `cost=[1,2,3,5]`,`val=[6,10,4]`, return `15`.
Input:
[1,2,3,5]
[6,10,4]
Output:
15

Explanation:
The first person can complete the 1st job, the 2nd job, the 3rd job, 1+2+3<=6.
The second person cancomplete the 1st job, the 2nd job, the 3rd job, and cannot complete the 4th job, 1+2+3<=10, 1+2+3+5>10.
The third person can complete  the 1st job, the 2nd job, and cannot complete the 3rd job,  1+2<=4, 1+2+3>4.
1+2+3+1+2+3+1+2=15, returning 15.
Example 2:

Given `cost=[3,7,3,2,5]`,`val=[10,20,12,8,17,25]`, return `78`.
Input:
[3,7,3,2,5]
[10,20,12,8,17,25]
Output:
78

Explanation:
The first person can complete the 1st job, the 2nd job, 3 + 7<=10.
The second person cancomplete the 1st job, the 2nd job, the 3rd job, the 4th job,the 5th job, 3+7+3+2+5<=20
The third person can complete  the 1st job, the 2nd job, and cannot complete the 3rd job,  3+7<=12,3+7+3>12.
The forth person can complete  the 1st job, and cannot complete the 2nd job,  3<=8,7+3>8.
The fifth person can complete  the 1st job, the 2nd job, the 3rd job, the 4th job, and cannot complete the 5th job,3+7+3+2<=17,3+7+3+2+5>17.
The sixth person cancomplete the 1st job, the 2nd job, the 3rd job, the 4th job,the 5th job, 3+7+3+2+5<=25
3+7+3+7+3+2+5+3+7+3+3+7+3+2+3+7+3+2+5=78, returning 78.

Notice
1<=n<=100000
1<=m<=100000
1<=val[i]<=100000
1<=cost[i]<=100000


Author: Yuan Li
Date: 1/3/2021
Difficulty: Medium
*/

class Solution {
public:
    /**
     * @param cost: the cost
     * @param val: the val
     * @return: the all cost
     */
    long long doingHomework(vector<int> &cost, vector<int> &val) {
        // Write your code here.
        long long res = 0;
    
        pre_sum_.push_back(0);
        
        for (int i = 0; i < cost.size(); ++i) {
            pre_sum_.push_back(pre_sum_[i] + cost[i]);
        }
        
        for (int v : val) {
            res += binarySearch(v);
        }
        
        return res;
    }
    
private:
    vector<long long> pre_sum_; 

private:
    long long binarySearch(int v) {
        int left = 0, right = pre_sum_.size() - 1;
        while (left + 1 < right) {
            int mid = (right - left) / 2 + left;
            if (pre_sum_[mid] == v) {
                return pre_sum_[mid];
            }
            if (pre_sum_[mid] < v) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        if (pre_sum_[right] <= v) {
            return pre_sum_[right];
        } 
        return pre_sum_[left];
    }
};
