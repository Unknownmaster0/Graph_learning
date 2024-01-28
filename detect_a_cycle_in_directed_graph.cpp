#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    
    // using only single array -> but here 1 means vis and 2 means vis as well as pathvis
    bool dfs(int node, vector<int>adj[], vector<int>& vis){
        vis[node] = 2;
        
        for(auto it:adj[node]){
            
            if(!vis[it]){
                if( dfs(it, adj, vis) == true) return true;
            }
            
            else if(vis[it] == 2)    return true;
        }
        
        vis[node] = 1;
        return false;
    }

    // using two array -> vis, pathvis [this one is better for understanding]
    bool dfs(int node, vector<int>adj[], vector<int>& vis, vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it:adj[node]){
            
            if(!vis[it]){
                if( dfs(it, adj, vis, pathvis) == true) return true;
            }
            
            else if(pathvis[it])    return true;
        }
        
        pathvis[node] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int>vis(V, 0);
        vector<int>pathvis(V, 0);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis) == true) return true;
            }
        }
        return false;
    }

int main()
{
    
    return 0;
}