#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = int(1e9+7);
        
        // first make the undirected graph
        vector<pair<int,int>> adj[n];
        
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> ways(n, 0);
        ways[0] = 1;
        
        // as the edge weight can be long long here.
        vector<long long> distance(n, INT_MAX);
        distance[0] = 0;
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
        
        pq.push({0, 0}); // distance, node
        
        while(!pq.empty()){
            
            auto it = pq.top();
            pq.pop();
            
            int currNode = it.second;
            long long currDis = it.first;
            
            for(auto itr:adj[currNode]){
                
                int adjNode = itr.first;
                int edW = itr.second;
                
                // int newdis = currDis + edW;
                
                // this is when we arriving the adjNode first time with minimum distance.
                if(currDis + edW < distance[adjNode]){
                    distance[adjNode] = currDis + edW;
                    pq.push({currDis + edW, adjNode});
                    
                    ways[adjNode] = ways[currNode] % mod;
                }
                // this is when we arrive with minimum distance again
                else if(currDis + edW == distance[adjNode])
                    ways[adjNode] = ( ways[adjNode] % mod + ways[currNode] % mod ) % mod;
            }
        }
        
        return (ways[n-1] % mod );
    }

int main()
{
    
    return 0;
}