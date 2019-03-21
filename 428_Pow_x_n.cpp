/*
428. Pow(x, n)
Implement pow(x, n).

Example
Pow(2.1, 3) = 9.261
Pow(0, 1) = 0
Pow(1, 0) = 1

Challenge
O(logn) time


Author: Yuan Li
Date: 8/4/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here
        if (n < 0) {
            return 1.0 / power(x, -n);
        }
        
        return power(x, n);
    }
    
    double power(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double tmp = power(x, n / 2);
        if (n % 2 == 0) {
            return tmp * tmp;
        }
        
        // when n == INT_MIN, always return x * tmp * tmp => inf
        return x * tmp * tmp;
    }
};


// Date: 3/21/2019
class Solution {
  public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        
        double tmp = x, res = 1;
        for (; n != 0; n /= 2, tmp *= tmp) {
            if (n % 2) {
                res *= tmp;
            }
        }
        
        return res;
    }
};

