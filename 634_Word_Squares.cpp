/*
634. Word Squares
Given a set of words without duplicates, find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y

Example
Given a set ["area","lead","wall","lady","ball"]
return [["wall","area","lead","lady"],["ball","area","lead","lady"]]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

Given a set ["abat","baba","atan","atal"]
return [["baba","abat","baba","atan"],["baba","abat","baba","atal"]]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

Notice
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.


Author: Yuan Li
Date: 1/19/2019 
Difficulty: Hard
*/

class Solution {
  public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        // write your code here
        vector<vector<string>> squares;
        if (words.empty()) {
            return squares;
        }
        
        // initialize hash table
        initPrefix(words);
        
        // search squares
        for (string word : words) {
            dfs({word}, squares);
        }
        
        return squares;
    }
    
  private:
    unordered_map<string, vector<string>> prefixes_; // prefix -> words

  private:
    void initPrefix(const vector<string> &words) {
        for (string word : words) {
            string prefix = "";
            for (char ch : word) {
                prefix += ch;
                prefixes_[prefix].push_back(word);
            }
        }
    }
    
    bool checkPrefix(string word, const vector<string> square) {
        int start = square.size();
        for (int r = start; r < square[0].size(); ++r) {
            string prefix = "";
            for (int c = 0; c < start; ++c) {
                prefix += square[c][r];
            }
            prefix += word[r];
            
            if (!prefixes_.count(prefix)) {
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(vector<string> square, vector<vector<string>> &squares) {
        int start = square.size();
        if (start == square[0].size()) {
            squares.push_back(square);
            return;
        }
        
        string prefix = "";
        for (int r = 0; r < start; ++r) {
            prefix += square[r][start];
        }
        
        for (string word : prefixes_[prefix]) {
            if (!checkPrefix(word, square)) {
                continue;
            }
            
            square.push_back(word);
            dfs(square, squares);
            square.pop_back();
        }
    }
};

