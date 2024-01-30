#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

//  simply needs the BFS traversal technique method.
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        
        for(auto it:edges){
            
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> dist(N , INT_MAX);
        dist[src] = 0;
        
        // simply push the src node in the queue with dist 0, and normally do the BFS traversal.
        /*  ********pair of queue is not mandatory *****
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                
                int v = it;
                if(d + 1 < dist[v]){
                    dist[v] = d + 1;
                    q.push({v, dist[v]});
                }
            }
        }
        */
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        
        for(int i = 0; i<N; i++){
            
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }

int main()
{
    
    return 0;
}