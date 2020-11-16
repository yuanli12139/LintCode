/*
424. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Example
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


Author: Yuan Li
Date: 12/1/2018 
Difficulty: Medium
*/

class Solution {
  public:
    /**
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> &tokens) {
        // write your code here
        for (string token : tokens) {
            if (isdigit(token.back())) {
                stk_.push(stoi(token));
            } else {
                int rhs = stk_.top();
                stk_.pop();
                
                int lhs = stk_.top();
                stk_.pop();
                
                stk_.push(compute(lhs, rhs, token));
            }
        }
        
        return stk_.top();
    }
    
  private:
    stack<int> stk_;
    
  private:
    int compute(const int lhs, const int rhs, const string &operand) {
        if (operand == "+") {
            return lhs + rhs;
        } else if (operand == "-") {
            return lhs - rhs;
        } else if (operand == "*") {
            return lhs * rhs;
        }
        return lhs / rhs;
    }
};

