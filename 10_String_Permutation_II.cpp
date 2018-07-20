/*
10. String Permutation II
Given a string, find all permutations of it without duplicates.

Example
Given "abb", return ["abb", "bab", "bba"].

Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].


Author: Yuan Li
Date: 7/19/2018 
Difficulty: Medium
*/

// dfs
class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        // write your code here
        vector<string> res;
        string perm;
        vector<bool> visited(str.length(), false);
        
        sort(str.begin(), str.end());
        dfs(str, perm, visited, res);
        
        return res;
    }
    
    void dfs(string &str, string perm, vector<bool> visited, vector<string> &res) {
        if (perm.size() == str.size()) {
            res.push_back(perm);
            return;
        }
        
        for (int i = 0; i < str.length(); ++i) {
            if (visited[i] == true)
                continue;
                
            if (i > 0 && str[i] == str[i-1] && !visited[i-1]) 
                continue;
                
            perm.push_back(str[i]);
            visited[i] = true;
            dfs(str, perm, visited, res);
            perm.pop_back();
            visited[i] = false;
        }
    }
};


// non-recursion
class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        // write your code here
        vector<string> res;
        
        sort(str.begin(), str.end());
        
        bool next = true;
        while (next) {
            res.push_back(str);
            next = nextPermutation(str);
        }
        
        return res;
    }
    
    bool nextPermutation(string &str) {
        if (str.length() <= 1)
            return false;
            
        int i = str.length() - 1;
        while (i > 0 && str[i-1] >= str[i]) {
            i--;
        }
        
        if (i > 0) {
            int j = str.length() - 1;
            while (i < j && str[i-1] >= str[j]) {
                j--;
            }
            
            swap(str, i - 1, j);
            reverse(str.begin() + i, str.end());
            
            return true;
        }
        
        return false;
    }
    
    void swap(string &str, int idx1, int idx2) {
        char temp = str[idx1];
        str[idx1] = str[idx2];
        str[idx2] = temp;
    }
};
