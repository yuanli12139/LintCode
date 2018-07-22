/*
121. Word Ladder II
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

All words have the same length.
All words contain only lowercase alphabetic characters.

Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]


Author: Yuan Li
Date: 7/21/2018 
Difficulty: Hard
*/

class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> dist;
        
        dict.insert(start);
        dict.insert(end);
        
        // BFS to build graph and record each node's distance to the end
        bfs(end, dict, graph, dist);
        
        // DFS to permutate all the shortest paths
        vector<vector<string>> res;
        vector<string> path = {start};
        dfs(start, end, graph, dist, path, res);
        
        return res;
    }
    
    void bfs(string &start, unordered_set<string> &dict, 
            unordered_map<string, vector<string>> &graph, unordered_map<string, int> &dist) {
        dist[start] = 0;
        
        queue<string> wordQueue;
        wordQueue.push(start);
        
        while (!wordQueue.empty()) {
            string curr_word = wordQueue.front();
            wordQueue.pop();
            
            vector<string> next_words = nextWords(curr_word, dict);
            for (string next_word : next_words) {
                graph[curr_word].push_back(next_word);
                
                if (!dist.count(next_word)) {
                    dist[next_word] = dist[curr_word] + 1;
                    wordQueue.push(next_word);
                }
            }
        }
    }

    void dfs(string &curr, string &end, unordered_map<string, vector<string>> &graph, 
            unordered_map<string, int> &dist, vector<string> path, vector<vector<string>> &res) {
        if (curr == end) {
            res.push_back(path);
            return;
        }          
        
        for (string next_word : graph[curr]) {
            if (dist[curr] == dist[next_word] + 1) {
                path.push_back(next_word);
                dfs(next_word, end, graph, dist, path, res);
                path.pop_back();
            }
        }
    }
    
    vector<string> nextWords(string &word, unordered_set<string> &dict) {
        vector<string> next_words;
        for (int i = 0; i < word.length(); ++i) {
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch == word[i]) {
                    continue;
                }
                
                string new_word = word.substr(0, i) + ch + word.substr(i+1);
                if (!dict.count(new_word)) {
                    continue;
                }
                
                next_words.push_back(new_word);
            }
        }
        
        return next_words;
    }
};
