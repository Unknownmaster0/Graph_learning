#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1/

    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int>dist(V, 1e8);
        dist[S] = 0;
        
        for(int i = 1; i<V; i++){
            for(auto it:edges){
                int node = it[0];
                int adjNode = it[1];
                int edW = it[2];
                
                if(dist[node] != 1e8 && dist[node] + edW < dist[adjNode]){
                    dist[adjNode] = dist[node] + edW;   
                }
            }
        }
        /*According to bellman ford algo -> all the nodes should be updated to the (n-1)th times only.
                                            And if after the (n-1)th times still the distance array is geeting updated then it means there is negative cycle present in the graph.
        */
        // last relaxation to check whether the graph containing negative cycle or not.
        for(auto it:edges){
            int node = it[0];
            int adjNode = it[1];
            int edW = it[2];
                
            if(dist[node] != 1e8 && dist[node] + edW < dist[adjNode]){
                return {-1};
            } 
        }
        
        return dist;
    }

int main()
{
    
    return 0;
}