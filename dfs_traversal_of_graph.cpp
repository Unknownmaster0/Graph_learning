#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}
    void solve(vector<int>&ans, int node, vector<int>adj[], int*visit)
    {
        visit[node] = 1;
        ans.push_back(node);
        
// Always this for loop to call dfs for the degree / neighbour of the node.
        for(auto it:adj[node])
        {
            if(!visit[it])
                solve(ans,it,adj,visit);
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // considering the starting node as 0.
        vector<int>ans ;
        int visit[V] = {0};
        int node = 0;
        solve(ans, node, adj, visit);
        return ans;
    }