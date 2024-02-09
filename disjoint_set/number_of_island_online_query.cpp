#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.youtube.com/watch?v=Rn6B-Q4SNyA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=52

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

        // if (size[ultiParent_u] < size[ultiParent_v])
        // {
        //     parent[ultiParent_u] = ultiParent_v;
        //     size[ultiParent_v] += size[ultiParent_u];
        // }
        // else
        // {
        //     parent[ultiParent_v] = ultiParent_u;
        //     size[ultiParent_u] += size[ultiParent_v];
        // }

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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{

    DisjointSet ds(n * m);

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int k = operators.size();

    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    vector<int> ans;
    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        int row = operators[i][0];
        int col = operators[i][1];

        if (vis[row][col])
        {
            ans.push_back(cnt);
            continue;
        }
        cnt++;
        vis[row][col] = 1;

        int base = row * m + col;

        for (int i = 0; i < 4; i++)
        {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            int idx = nrow * m + ncol;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                if (vis[nrow][ncol] && ds.findParent(base) != ds.findParent(idx))
                {
                    ds.unionBySize(base, idx);
                    cnt--;
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{

    return 0;
}