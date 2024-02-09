#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/account-merge/1

// this is disjoint set class which we have made in previously in this folder only. only copy paste this.
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
            size[ultiParent_v] += ultiParent_u;
        }
    }
};

class Solution
{
public:
    //  O(N*M*logN) - where N is the size of accounts and M is the size of number of strings for a name.
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // n = accounts.size() and m = accounts[i].size();
        int n = accounts.size();
        // create disjoint data structure.
        DisjointSet ds(n);

        // create the mapping from mail to nodes. // name is mapped to nodes number.

        // O(size of accounts)
        unordered_map<string, int> mailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {

                string mail = accounts[i][j];

                if (mailNode.find(mail) != mailNode.end())
                {
                    ds.unionBySize(i, mailNode[mail]);
                }
                else
                {
                    mailNode[mail] = i;
                }
            }
        }

        // now traverse over the mailNode map and store corresponding ans
        vector<string> store[n];

        // O(size of accounts) [at worst case all mails are pushed into the map]
        for (auto it : mailNode)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            store[node].push_back(mail);
        }

        vector<vector<string>> ans;

        //  O(N * M * log N)
        for (int i = 0; i < n; i++)
        {
            if (store[i].size() == 0)
                continue;

            // N * log N
            sort(store[i].begin(), store[i].end());
            string name = accounts[i][0];

            vector<string> temp;
            temp.push_back(name);

            for (auto it : store[i])
                temp.push_back(it);

            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{

    return 0;
}