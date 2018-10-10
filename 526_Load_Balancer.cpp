/*
526. Load Balancer
Implement a load balancer for web servers. It provide the following functionality:

Add a new server to the cluster => add(server_id).
Remove a bad server from the cluster => remove(server_id).
Pick a server in the cluster randomly with equal probability => pick().

Example
At beginning, the cluster is empty => {}.

add(1)
add(2)
add(3)
pick()
>> 1         // the return value is random, it can be either 1, 2, or 3.
pick()
>> 2
pick()
>> 1
pick()
>> 3
remove(1)
pick()
>> 2
pick()
>> 3
pick()
>> 3


Author: Yuan Li
Date: 10/9/2018 
Difficulty: Medium
*/

class LoadBalancer {
  public:
    LoadBalancer() {
        // do intialization if necessary
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        // write your code here
        val_idx_[server_id] = servers_.size();
        servers_.push_back(server_id);
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // write your code here
        int rm_idx = val_idx_[server_id];
        
        // swap to the last
        servers_[rm_idx] = servers_.back();
        val_idx_[servers_.back()] = rm_idx;
        
        // remove
        servers_.pop_back();
        val_idx_.erase(server_id);
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        // write your code here
        return servers_[rand() % servers_.size()];
    }
    
  private:
    unordered_map<int, int> val_idx_;
    vector<int> servers_;
};

