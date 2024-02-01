#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

// Time complexity -> O(e * log v)[dijkstra algo time] + O(v) [for pushing ans nodes in ans vector]
vector<int> shortestPath(int n, int m, vector<vector<int>> edges)
{
    // make adjacency list first;
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        int v = it[0];
        int adjNode = it[1];
        int edgeWeight = it[2];
        adj[v].push_back({adjNode, edgeWeight});
        adj[adjNode].push_back({v, edgeWeight});
    }

    vector<int> distance(n + 1, INT_MAX);
    vector<int> path(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        path[i] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1}); // distance, source node

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        int node = it.second, dist = it.first;

        for (auto itr : adj[node])
        {
            int adjNode = itr.first;
            int edgeWeight = itr.second;
            if (edgeWeight + dist < distance[adjNode])
            {
                distance[adjNode] = edgeWeight + dist;
                path[adjNode] = node;
                q.push({distance[adjNode], adjNode});
            }
        }
    }

    // case -> when you can't able to reach at nth node
    if (distance[n] == INT_MAX)
        return {-1}; // returning vector containing -1.

    vector<int> ans;

    /*  ans.push_back(n);
        int i = n;
        while (i > 1)
        {
            ans.push_back(path[i]);
            i = path[i];
        }
    */

    // better to be done like this
    int node = n;
    // O(v)
    while (path[node] != node)
    {
        ans.push_back(node);
        node = path[node];
    }
    ans.push_back(1);

    reverse(ans.begin(), ans.end());
}

int main()
{

    return 0;
}