#!/usr/bin/python3

'''
54. String to Integer (atoi)
Implement function atoi to convert a string to an integer.

If no valid conversion could be performed, a zero value is returned.

If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Example
"10" => 10
"-1" => -1
"123123123123123" => 2147483647
"1.0" => 1


Author: Yuan Li
Date: 8/7/2018 
Difficulty: Hard
'''

class Solution:
    """
    @param str: A string
    @return: An integer
    """
    def atoi(self, str):
        # write your code here
        start = 0
        while start < len(str):
            if str[start] == ' ' or str[start] == '+' or str[start] == '-':
                start += 1
            else:
                break
        
        if start == len(str):
            return 0
        
        # "  +-1111 " => 0
        if start > 1 and str[start-2] != ' ':
            return 0
            
        if str[start].isdigit():
            end = start + 1
            while end < len(str):
                if str[end].isdigit():
                    end += 1
                else:
                    break
            
            res = int(str[start:end])
            if start > 0 and str[start-1] == '-':
                res = -res
            
            if res < -2147483648:
                return -2147483648
            
            if res > 2147483647:
                return 2147483647
            
            return res
            
        return 0


'''
Reference
https://www.youtube.com/watch?v=vvua0G0eqsM

Date: 9/8/2018
'''

class Solution:
    """
    @param str: A string
    @return: An integer
    """
    def atoi(self, str):
        # write your code here
        res = 0
        if not str:
            return res
        
        str = str.strip()
        
        sign = 1
        start = 0
        if str[0] == '+':
            start += 1
        elif str[0] == '-':
            start += 1
            sign = -1

        for i in range(start, len(str)):
            if not str[i].isdigit():
                break
                
            res = res * 10 + int(str[i])
            if sign == 1 and res > 2147483647:
                return 2147483647
            
            if sign == -1 and res > 2147483648:
                return -2147483648
                
        return res * sign
