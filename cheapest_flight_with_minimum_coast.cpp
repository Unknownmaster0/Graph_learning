#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

/*Approach -> Simply using the dijkstra algo but with some changes.
            This time queue would contains (stops at 1st , node val at 2nd , cost at 3rd) // we will not insert cost first b/c this will give wrong answer.

            And we are using only queue not the priority queue data strcture b/c the intention of using the priority queue is to get the smallest value first.
            While when we start from src city then stop = 0 and stop will increasing in ascending order only.
            That's why no need of priority queue.
            Simply use queue data structure.
*/

// Time complexity -> As what the dijkstra will take O(E); [not E * log V] as we are not using the priority queue here which will take extra (log V) [for push and pop]

    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        
        /* first make the graph */
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>costing(n, INT_MAX);
        costing[src] = 0;
        
        queue<pair<int,pair<int,int>> > q;
        q.push({0,{src,0}}); // stops , source node, distance
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int city = it.second.first;
            int cost = it.second.second;
            
            if(stops > k )
                continue;
            
            for(auto itr:adj[city]){
                
                int adjcity = itr.first;
                int adjcost = itr.second;
                
                int newcost = cost + adjcost;
                
                if(costing[adjcity] > newcost && stops <= k){
                    costing[adjcity] = newcost;
                    q.push({stops+1 , {adjcity, newcost}});
                }
            }
        }
        
        if(costing[dst] == INT_MAX){
            return -1;
        } 
        
        return costing[dst];
    }

int main()
{
    
    return 0;
}