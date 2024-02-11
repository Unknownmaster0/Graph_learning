#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/eventual-safe-states/1

/* solving this question is more efficient from the DFS algo of cycle detection method , but you should also know the topo sort approach.

    Why the topo sort approach is not efficient ?
     -> Because, it is more time taking than DFS one. [DFS time = O(v + e) in worst case] [topo sort = O(v + e) + O(v * log(v)) in worst case.]
*/

/*Time complexity -> O(v + e) + O(v * log(v)) [extra one for sorting the safeNodes vector]
    Space complexity -> O(v) + O(v) [something more than dfs algo.]
*/
// using topological sort algorithm 
    vector<int> eventualSafeNodes(int v, vector<int> adj[])
    {
        // first make the reverse graph or adjacent list
        vector<int> adjrev[v];
        int indegree[v] = {0};
        
        for(int i = 0; i<v; i++)
        {
            for(auto it:adj[i]){
                
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        // now simple apply the topo sort
        queue<int> q;
        for(int i = 0; i<v; i++)
            if(indegree[i] == 0)    q.push(i);
        
        vector<int> safeNodes;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            safeNodes.push_back(node);
            
            for(auto it:adjrev[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
        
    }

    bool dfs(int node, vector<int>adj[], vector<int>& vis, vector<int>& pathvis, int check[]){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it:adj[node]){
            
            if(!vis[it]){
                if( dfs(it, adj, vis, pathvis, check) == true) return true;
            }
            
            else if(pathvis[it]) return true;
            
        }
        
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
     
        vector<int>safeNode;
        vector<int>vis(V, 0);
        vector<int>pathvis(V, 0);
        
        int checkSafe[V] = {0};
        
        for(int i = 0; i<V; i++){
            
            if(!vis[i])
                dfs(i, adj, vis, pathvis, checkSafe);
        }
        
        for(int i = 0; i<V; i++){
            if(checkSafe[i] == 1) safeNode.push_back(i);
        }
        
        return safeNode;
    }

int main()
{
    
    return 0;
}