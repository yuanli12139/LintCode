/*
132. Word Search II
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. A word can start from any position in the matrix and go left/right/up/down to the adjacent position. One character only be used once in one word.

Example
Given matrix:

doaf
agai
dcan
and dictionary:

{"dog", "dad", "dgdg", "can", "again"}

return {"dog", "dad", "can", "again"}

dog:
[d][o] a  f
 a [g] a  i
 d  c  a  n

dad:
[d] o  a  f
[a] g  a  i
[d] c  a  n

can:
 d  o  a  f
 a  g  a  i
 d [c][a][n]

again:
 d  o  a  f
[a][g][a][i]
 d  c  a [n]

Challenge
Using trie to implement your algorithm.


Author: Yuan Li
Date: 7/22/2018 
Difficulty: Hard
*/

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        // write your code here
        vector<string> res;
        unordered_set<string> wordSet;
        
        if (board.size() == 0 || board[0].size() == 0) {
            return res;
        }
        
        unordered_map<string, bool> prefixIsWord;
        for (string word : words) {
            // a word could be both a prefix and a word
            // make sure all the words are true
            prefixIsWord[word] = true;
            
            for (int l = 1; l < word.length(); ++l) {
                string prefix = word.substr(0, l);
                if (!prefixIsWord.count(prefix)) {
                    prefixIsWord[prefix] = false;
                }
            }
        }
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        string path;
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                visited[r][c] = true;
                dfs(board, path + board[r][c], r, c, prefixIsWord, visited, wordSet);
                visited[r][c] = false;
            }
        }
        
        res.insert(res.end(), wordSet.begin(), wordSet.end());
        return res;
    }
    
    void dfs(vector<vector<char>> &board, string path, int r, int c,
            unordered_map<string, bool> &prefixIsWord, vector<vector<bool>> &visited, 
            unordered_set<string> &wordSet) {
        if (!prefixIsWord.count(path)) {
            return;
        }          
        
        if (prefixIsWord[path]) {
            wordSet.insert(path);
        }
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; ++i) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            
            if (!isValid(board, next_r, next_c) || visited[next_r][next_c]) {
                continue;
            }
            
            visited[next_r][next_c] = true;
            dfs(board, path + board[next_r][next_c], next_r, next_c, prefixIsWord, visited, wordSet);
            visited[next_r][next_c] = false;
        }
    }
    
    bool isValid(vector<vector<char>> &board, int next_r, int next_c) {
        return next_r >= 0 && next_r < board.size() && 
                next_c >= 0 && next_c < board[0].size();
    }
};
