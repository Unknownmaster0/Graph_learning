#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}

class Solution {
    private:
    int timer = 1;
    void dfs(int node, int parent, int vis[], int tinsert[], int lowest[], vector<int>adj[], vector<int>&mark)
    {
        vis[node] = 1;
        tinsert[node] = lowest[node] = timer++;
        
        int child = 0;
        
        for(auto it:adj[node])
        {
            if(it==parent)  continue;
            else if(!vis[it])
            {
                dfs(it, node, vis, tinsert, lowest, adj, mark);
                lowest[node] = min(lowest[node], lowest[it]);
                
                // check for condition of articulation point.
                if(lowest[it] >= tinsert[node] && parent != -1){
                    mark[node] = 1; // pushed the articulation point into the map.
                }
                child++;
            }
            else{
                lowest[node] = min(lowest[node], tinsert[it]);
            }
        }
        
        if(child > 1 && parent == -1)   mark[node] = 1;
    }
    
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        //step 1-> intialise all the things.
        int vis[V] = {0};
        int tinsert[V];
        int lowest[V];
        vector<int> points;
        vector<int> mark(V, 0);
        
        for(int i = 0; i<V; i++)
        {
            if(!vis[i])
                dfs(0, -1,vis, tinsert, lowest, adj, mark);
        }
        
        for(int i=0; i<V; i++){
            if(mark[i]) points.push_back(i);
        }
        
        if(points.size() == 0)  return {-1};
        
        return points;
    }
};