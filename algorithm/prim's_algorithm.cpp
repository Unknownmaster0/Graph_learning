#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    int vis[V] = {0};

    int pathSum = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // we also not need the pq of storing three data for this question, as parent is not needed here.
    pq.push({0, {0, -1}}); // edge weight, node, parent.

    // we must use pq.push({0,0}); // edge weight, node.

    // time complex ->
    while (!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();

        int dist = itr.first;
        int node = itr.second.first;
        int parent = itr.second.second;

        if (vis[node])
        { // we are not using the parent == -1 because here we don't need the parent.
            continue;
            // parent is needed to store the graph of the minimum spanning tree.
        }
        // here we don't need the parent kind of thing, as we have told to find sum of path only.
        /*
                    if(parent != -1){
                        vis[node] = 1;
                        pathSum += dist;
                    }
                    else if(parent == -1){
                        vis[node] = 1;
                    }*/
        vis[node] = 1;
        pathSum += dist;

        // Time complexity -> O(E)
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];

            if (!vis[adjNode])
            {
                pq.push({edW, {adjNode, node}});
            }
        }
    }

    return pathSum;
}

int main()
{

    return 0;
}