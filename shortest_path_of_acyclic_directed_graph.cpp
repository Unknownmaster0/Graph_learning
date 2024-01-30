#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<limits.h>
using namespace std;

    
// problem link -> https://geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

    void dfs(int node, vector<vector<pair<int,int>>>& adj, int vis[], stack<int>& st){
        
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it.first])  dfs(it.first, adj, vis, st);
        }
        
        st.push(node);
    }
    

//Note -> ******** here the source node is always 0 fixed. ***********

    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        
        // step 1 -> make the adjcaceny list.
        vector<vector<pair<int,int>> > adj(n);
        
        for(auto it:edges){
                
            // it[0] -> node , it[1] -> neighbouring node, it[2] -> distance.
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // // print adj list
        // for(int i = 0; i<n; i++){
        //     cout<<"i -> "<<i<<" -> neighbours -> ";
        //     for (auto& neighbor : adj[i]) {
        //         cout << neighbor.first << " , " << neighbor.second << " | ";
        //     }
        //     cout << endl;
        // }
        
        // now find the topological sort using the dfs approach
        // step 2 -> Do the topological sort
        int vis[n] = {0};
        stack<int> st;
        
        for(int i = 0; i<n; i++){
            
            if(!vis[i]) dfs(i, adj, vis, st);
        }

// step 3 -> do the distance thing
        vector<int>dist (n, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            
            int node = st.top();
            st.pop();
            
            // it means that Node is not able to visit by anyone.
            if(dist[node] == INT_MAX){
              
                dist[node] = -1;
                continue;
            } 
            
            for(auto it:adj[node]){
                
                int next = it.first;
                int nextd = it.second;
                
                if(dist[node] + nextd < dist[next]){
                    dist[next] = dist[node] + nextd;
                }
            }
        }
        
        return dist;
    }

int main()
{
    
    return 0;
}