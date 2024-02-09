#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// problem link ->

// kosaraju's algorithm -> An algorithm to find the number of Strongly connected component in the graph.
class solution{
    // normal dfs traversal -> topo sort
    void sorting(int node, stack<int>& st, int vis[], vector<vector<int>> &adj){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]) sorting(it, st, vis, adj);
        }
        
        st.push(node);
        return;
    }
    
    // plain dfs
    void callDfs(int node, vector<int>revAdj[], int vis[])
    {
        vis[node] = 1;
        
        for(auto it:revAdj[node]){
            if(!vis[it]) callDfs(it, revAdj, vis);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // step 1-> sort all the nodes on the basis of finishing time.
        stack<int> sortedNodes;
        int vis[V] = {0};
        for(int i = 0; i<V; i++){
            if(!vis[i]) sorting(i, sortedNodes, vis, adj);
        }
        
        // step 2 -> reverse the graph 
        vector<int>revAdj[V];
        for(int i = 0; i<V; i++)
        {
            vis[i] = 0; // making the vis[v] zero again.
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
            }
        }
        
        // step 3 -> call dfs for each node in the stack.
        int cntScc = 0;
        while(!sortedNodes.empty()){
            int node = sortedNodes.top();
            sortedNodes.pop();
            
            if(!vis[node]){
                cntScc++;
                callDfs(node, revAdj, vis);
            }
        }
        
        return cntScc;
    }
};

int main()
{

    return 0;
}