/*
589. Connecting Graph
Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.

You need to support the following method:

connect(a, b), add an edge to connect node a and node b`.
query(a, b), check if two nodes are connected

Example
5 // n = 5
query(1, 2) return false
connect(1, 2)
query(1, 3) return false
connect(2, 4)
query(1, 4) return true


Author: Yuan Li
Date: 12/21/2018 
Difficulty: Medium
*/

class ConnectingGraph {
  public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        for (int i = 1; i <= n; ++i) {
            father_[i] = i;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        father_[find(a)] = find(b);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        return find(a) == find(b);
    }
    
  private:
    unordered_map<int, int> father_;
    
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

