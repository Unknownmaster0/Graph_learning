#include<iostream>
#include<vector>
#include<queue>
using namespace std;

    bool detectCycle(int i, vector<int>adj[], int* vis){
        vis[i] = 1;
        
        queue< pair<int,int> > q;
        q.push({i,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                // if the it is already visited but it is not the parent of the node, then it form the cycle.
                else if(it != parent ){
                    return true;
                }
                // if the node is also present in the itself ajacency list, then there is self loop.
                else if(it == node){
                    return true;
                }
            }
        }
        
        return false;
    }


    int isTree(int n, int m, vector<vector<int>> &edge) {
        // for a tree -> no. of edges is always 1 less than the total vertices.
        if(n <= m) return 0;
        
        int vis[n] = {0};
        vector<int>adj[n];
        
        for(int i = 0; i<m; i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        
        // now call bfs algorithm.
        // one extra thing is added here -> is the connected component should not more than 1.
        int cc = 0; // cc -> connected component.
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis) == true)
                    return 0;
                ++cc;
            }
        }
        return 1 && cc == 1;
    }

int main()
{
    
    return 0;
}