#include<iostream>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        
        vector<int>distance(V, INT_MAX);
        distance[S] = 0;
        
        st.insert({0,S});
        
        while(!st.empty())
        {
            pair<int,int> p = *( st.begin() );
            int node = p.second;
            int dist = p.first;
            
            st.erase({dist,node});
            
            for(auto it:adj[node])
            {
                int adjNode = it[0];
                int edgeweight = it[1];
                
                if(dist + edgeweight < distance[adjNode])
                {
                    if(distance[adjNode] != INT_MAX){
                        st.erase({distance[adjNode],adjNode});
                    }
                    distance[adjNode] = dist + edgeweight;
                    st.insert({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }

int main()
{
    
    return 0;
}