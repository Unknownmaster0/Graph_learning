// question name -> City With the Smallest Number of Neighbors at a Threshold Distance
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

/*Applying DIJKSTRA in place of Floyd warshell in same question*/
int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector< pair<int,int> >adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        for(int i = 0; i<n; i++)    dist[i][i] = 0; // marking the dist of visiting same city as 0.
        
        //set method of implementing the dijkstra algo.
        for(int src = 0; src<n; src++){
            set< pair<int,int> > st;
            st.insert({0,src});
            
            while(!st.empty()){
                auto it = *(st.begin());
                int wt = it.first;
                int city = it.second;
                st.erase(it);
                
                for(auto itr:adj[city]){
                    int adjCity = itr.first;
                    int edW = itr.second;
                    
                    if(edW + wt < dist[src][adjCity]){
                        dist[src][adjCity] = wt + edW;
                        st.insert({wt+edW, adjCity});
                    }
                }
            }
        }
    
        // this is same->
        pair<int,int> city;
        city = {-1,1e9};
        for(int i = 0; i<n; i++){
            int cntconnectedcity = 0;
            for(int j = 0; j<n; j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    cntconnectedcity ++;
                }
            }
            if(cntconnectedcity <= city.second){
                city.first = i;
                city.second = cntconnectedcity;
            }
        }
        
        return city.first;
}

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