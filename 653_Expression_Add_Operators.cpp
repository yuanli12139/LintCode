/*
653. Expression Add Operators
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Example
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []


Author: Yuan Li
Date: 1/22/2019 
Difficulty: Hard
*/

class Solution {
  public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        // write your code here
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
    
  private:
    void dfs(const string &num, const int target, int start, int sum, int lastF,
            string expr, vector<string> &res) {
        if (start == num.size()) {
            if (sum == target) {
                res.push_back(expr);
            }
            return;
        }
        
        for (int i = start; i < num.size(); ++i) {
            string f = num.substr(start, i - start + 1);
            long x = stol(f);
            
            if (start == 0) {
                dfs(num, target, i + 1, x, x, to_string(x), res);
            } else {
                dfs(num, target, i + 1, sum + x, x, expr + '+' + f, res);
                dfs(num, target, i + 1, sum - x, -x, expr + '-' + f, res);
                dfs(num, target, i + 1, sum - lastF + lastF * x, lastF * x, expr + '*' + f, res);
            }
            
            if (x == 0) { // next x should not start with 0
                return;
            }
        }
    }
};

