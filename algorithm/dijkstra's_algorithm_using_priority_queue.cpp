#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// class comparator{
//     public:
//         bool operator()(pair<int,int> p1, pair<int,int> p2)
//         {
//             return p1.first > p2.first;
//         }
// };

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // applying the dijkstra algorithm using the priority queue data structure.
        // priority_queue<pair<int,int>,vector<pair<int,int>>, comparator> minHeap; -> this is also correct method of minHeap
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > minHeap; // but this syntax is better.
        
        minHeap.push({0,S});
        
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        
        while(!minHeap.empty())
        {
            int node = minHeap.top().second;
            int dis = minHeap.top().first;
            
            minHeap.pop();
            
            for(auto it:adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dis + edgeWeight < distance[adjNode]){
                    distance[adjNode] = dis + edgeWeight;
                    minHeap.push({distance[adjNode], adjNode});
                }
            }
        }
        
        return distance;
    }


int main()
{
    
    return 0;
}