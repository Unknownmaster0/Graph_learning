#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{

    vector<int> rank, parent, size;

public:
    // constructor.
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // taking for 1-based indexing.
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // method to find ultimate parent of node.
    // Time complexity -> O(4* alpha)
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    // Time complexity -> O(4* alpha)
    // method to do the union of two nodes by rank
    void unionByrank(int u, int v)
    {
        int ultiParent_u = findParent(u);
        int ultiParent_v = findParent(v);

        if (ultiParent_u == ultiParent_v)
            return;

        if (rank[ultiParent_u] > rank[ultiParent_v])
        {
            parent[ultiParent_v] = ultiParent_u;
        }
        else if (rank[ultiParent_v] > rank[ultiParent_u])
        {
            parent[ultiParent_u] = ultiParent_v;
        }
        else
        {
            parent[ultiParent_v] = ultiParent_u;
            rank[ultiParent_u]++;
        }
    }

    // Time complexity -> O(4* alpha)
    void unionBySize(int u, int v)
    {
        int ultiParent_u = findParent(u);
        int ultiParent_v = findParent(v);

        if (ultiParent_u == ultiParent_v)
            return;

        if (size[ultiParent_u] > size[ultiParent_v])
        {
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
        else
        {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
    }
};

// int main()
// {
//     // DisjointSet d(6);
//     // d.unionBySize(1, 3);
//     // d.unionBySize(2, 1);
//     // d.unionBySize(4, 5);
//     // // check at any point of formation of graph if two different node belongs to same component or not.
//     // // find parent of the two nodes.
//     // d.unionBySize(3, 6);
//     // d.unionBySize(5, 2);
//     // if (d.findParent(5) == d.findParent(3))
//     // {
//     //     cout << "from same component" << endl;
//     // }
//     // else
//     //     cout << "NOt from same component" << endl;
//     return 0;
// }