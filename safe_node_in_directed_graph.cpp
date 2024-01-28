#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/eventual-safe-states/1

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

  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
/*        // BRUTFORCE APPROACH
        vector<int>ans;
        vector<int>terminal;
        
        for(int i = 0; i<V; i++){
            
            // this is the terminal nodes.
            if(adj[i].size() == 0 ){
                
                terminal.push_back(i);
                ans.push_back(i);
            }
        }
        
        for(int i = 0; i<V; i++)
        {
            if(adj[i].size() == 1){
                
                for(int j = 0; j<terminal.size(); j++){
                    
                    if(adj[i][0] == terminal[j]){
                        
                        ans.push_back(i);
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
     */
     
        vector<int>safeNode;
        vector<int>vis(V, 0);
        vector<int>pathvis(V, 0);
        
        int checkSafe[V] = {0};
        
        for(int i = 0; i<V; i++){
            
            if(!vis[i])
            {
                dfs(i, adj, vis, pathvis, checkSafe);
            }
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