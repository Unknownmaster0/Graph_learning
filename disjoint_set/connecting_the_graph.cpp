#include <iostream>
#include <vector>
#include "disjoint_set_data_structure.cpp" // including the disjoint set class. Now, we can access the disjoint set class here.
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/connecting-the-graph/1

// time complexity -> O(N + M) [N = NUmber of nodes, M = size of edge vector.]
int Solve(int n, vector<vector<int>> &edge)
{

    DisjointSet ds(n);
    int extraEdges = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        if (ds.findParent(edge[i][0]) == ds.findParent(edge[i][1]))
            extraEdges++;
        else
            ds.unionBySize(edge[i][0], edge[i][1]);
    }

    // cnt ultimate parent
    int cntParent = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findParent(i) == i)
            cntParent++;
    }

    if (cntParent - 1 <= extraEdges)
        return cntParent - 1;
    return -1;
}

int main()
{

    return 0;
}