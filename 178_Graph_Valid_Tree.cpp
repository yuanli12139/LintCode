/*
178. Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Notice
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


Author: Yuan Li
Date: 12/26/2018 
Difficulty: Medium
*/

// union find
class Solution {
  public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (edges.size() != n - 1) {
            return false;
        }
        
        count_ = n;
        for (int i = 0; i < n; ++i) {
            father_[i] = i;
        }
        
        for (auto e : edges) {
            merge(e);
        }
                
        return count_ == 1;
    }
    
  private:
    unordered_map<int, int> father_;
    int count_;
    
  private:
    void merge(const vector<int> &edge) {
        int root0 = find(edge[0]);
        int root1 = find(edge[1]);
        if (root0 != root1) {
            father_[root0] = root1;
            --count_;
        }
    }
    
    int find(int node) {
        vector<int> path;
        while (father_[node] != node) {
            path.push_back(node);
            node = father_[node];
        }
        
        for (int n : path) {
            father_[n] = node;
        }
        
        return node;
    }
    
    // // recursion
    // int find(int node) {
    //     if (father_[node] == node) {
    //         return node;
    //     }
        
    //     return father_[node] = find(father_[node]);
    // }
};


// Date: 12/27/2018 
// BFS
class Solution {
  public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (edges.size() != n - 1) {
            return false;
        }
        
        if (edges.empty()) {
            return true;
        }
        
        return bfs(buildGraph(edges), edges[0][0]) == n;
    }
    
  private:
    typedef unordered_map<int, unordered_set<int>> graph;
    
    graph buildGraph(const vector<vector<int>> &edges) {
        graph g;
        for (auto edge : edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        
        return g;
    }
  
    int bfs(const graph &g, int start) {
        queue<int> q;
        q.push(start);
        
        unordered_set<int> visited;
        visited.insert(start);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // graph[cur] calls non-const member function since it adds 
            // a default value when the item looked up is not found
            for (int nxt : g.at(cur)) { 
                if (!visited.count(nxt)) {
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        
        return visited.size();
    }
};

