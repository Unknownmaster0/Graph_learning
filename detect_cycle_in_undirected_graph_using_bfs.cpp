#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    
    return 0;
}

    bool dfs(int i, int parent,vector<int> adj[], int *vis)
    {
        vis[i] = true;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(it, i, adj, vis) == true)
                    return true;
            }
            else if(it != parent){
                return true;   
            }
        }
        return false;
    }

    bool bfs(int i, vector<int>adj[], int* vis){
        vis[i] = 1;
        
        queue< pair<int,int> > q;
        q.push({i,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                // if the it is already visited but it is not the parent of the node, then it form the cycle.
                else if(it != parent ){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // make a visited array
        int vis[V] = {0};
        
        // now call bfs algorithm.
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(bfs(i, adj, vis) == true)
                    return true;
                // if(dfs(i,-1,adj, vis) == true)
                //     return true;
            }
        }
        return false;
    }