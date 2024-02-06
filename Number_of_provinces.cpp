// problem link -> https://practice.geeksforgeeks.org/problems/number-of-provinces/1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// this problem can also be solved using Disjoint set Data Structure , go and check the code at gfg problem link above.

int main()
{
    
    return 0;
}

    void bfs(int node, vector<int> adjList[], vector<int>& visited)
    {
        queue<int>q;
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto it:adjList[front])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    void dfs(int node, vector<int> adjList[], vector<int>&visited)
    {
        visited[node] = 1;
        for(auto it:adjList[node])
        {
            if(!visited[it])
                dfs(it, adjList, visited);
        }
    }

  // 0 based indexing.
    int numProvinces(vector<vector<int>> adj, int V) {
// here the adjacency matrix is given but we learn on the adjacency list. 
// so conver the adjacency matrix to adjacency list.
        vector<int>adjList[V];
        for(int i = 0; i<V; i++)
        {
            for(int j = 0; j<V; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // use the Dfs traversal / Bfs traversal to visit all the nodes of the graph.
        vector<int>visited(V, 0);
        int countProvinces = 0;
        for(int i = 0; i< V; i++){
            if(!visited[i])
            {
                countProvinces++;
                dfs(i, adjList, visited);
            }
        }
        return countProvinces;
    }