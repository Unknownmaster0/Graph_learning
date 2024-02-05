// question name -> City With the Smallest Number of Neighbors at a Threshold Distance
#include <iostream>
#include <vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

// Time complexity -> O(N^3)
int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{

    // applying floyd warshell
    vector<vector<int>> vec(n, vector<int>(n, 1e9));

    for (auto it : edges)
    {
        int u = it[0], v = it[1], dis = it[2];
        vec[u][v] = dis;
        vec[v][u] = dis;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                vec[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
            }
        }
    }

    pair<int, int> city;
    city = {-1, 1e9};
    for (int i = 0; i < n; i++)
    {
        int cntconnectedcity = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && vec[i][j] <= distanceThreshold)
            {
                cntconnectedcity++;
            }
        }
        if (cntconnectedcity <= city.second)
        {
            city.first = i;
            city.second = cntconnectedcity;
        }
    }

    return city.first;
}

int main()
{

    return 0;
}