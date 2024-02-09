#include <iostream>
#include <vector>
using namespace std;

// problem link -> https://leetcode.com/problems/critical-connections-in-a-network/submissions/1170708657/

class Solution {
private:
    int timer = 1; // may also start from 0.
    void dfs(int node, int parent, vector<int>&vis, int tinsert[], int lowest[], 
                                                        vector<int>adj[], vector<vector<int>>&bridges){
        vis[node] = 1;
        tinsert[node] = lowest[node] = timer;
        timer++;

        for(auto it:adj[node]){
            if(it == parent) continue;
            else if(!vis[it]){
                dfs(it, node, vis, tinsert, lowest, adj, bridges);
                // updated the lowest time if the adjacent has lower lowest time.
                lowest[node] = min(lowest[node], lowest[it]);

                // edge be = (node-----it)
                if(tinsert[node] < lowest[it]) // means there is bridge.
                    bridges.push_back({node, it});
            }
            else{
                // if the adjacent node is already visited then curr node, then it can never be the bridge.
                // like  7
                //      / \
                //     8---9  // if curr node is 9 and adj node is 7, then dfs(8) called the dfs(9)
                // so the parent for 9 is 8, and 7 is adjNode, but 7 is already visited then 9, thus It can't be 
                // bridge , on removing edge 7--9 it still be connected via 8.
                lowest[node] = min(lowest[node], lowest[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // step 1 -: first make the graph
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //step 2 -> start making the dfs traversal on the graph.
        vector<int>vis(n, 0);
        int tinsert[n];
        int lowest[n];
        vector<vector<int>> bridges;
        // assuming the graph has single component, thus calling dfs for 0 only.
        dfs(0, -1, vis, tinsert, lowest, adj, bridges);
        return bridges;
    }
};

int main()
{

    return 0;
}