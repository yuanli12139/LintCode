/*
590. Connecting Graph II
Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.

You need to support the following method:

connect(a, b), an edge to connect node a and node b
query(a), Returns the number of connected component nodes which include node a.

Example
5 // n = 5
query(1) return 1
connect(1, 2)
query(1) return 2
connect(2, 4)
query(1) return 3
connect(1, 4)
query(1) return 3


Author: Yuan Li
Date: 12/22/2018 
Difficulty: Medium
*/

class ConnectingGraph2 {
  public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        // do intialization if necessary
        for (int i = 1; i <= n; ++i) {
            father_[i] = i;
            count_[i] = 1;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father_[root_a] = root_b;
            count_[root_b] += count_[root_a];
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here
        return count_[find(a)];
    }
    
  private:
    unordered_map<int, int> father_;
    unordered_map<int, int> count_;
    
  private:
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

