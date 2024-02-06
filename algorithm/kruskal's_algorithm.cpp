#include <iostream>
#include <vector>
#include <algorithm>
// from this line I have included my class Disjoint in this code so, that I can use it here.
#include "../disjoint_set./disjoint_set_data_structure.cpp"
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/number-of-provinces/1

int spanningTree(int V, vector<vector<int>> adj[])
{
    // Solving this question using Kruskal's algorithm
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            // it[0] -> adjacent node of i
            // it[1] -> wt of the node to nodei
            // i -> nodei
            edges.push_back({it[1], {it[0], i}}); // wt, node1, node2
        }
    }

    sort(edges.begin(), edges.end());

    // creating the disjoint set data structure.
    DisjointSet d(V);

    int pathWt = 0;

    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (d.findParent(u) != d.findParent(v))
        {
            pathWt += wt;
            d.unionBySize(u, v);
        }
    }

    return pathWt;
}

int main()
{

    return 0;
}