#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    
    return 0;
}
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        queue<int>q;
        vector<bool>visited(v,0);
        q.push(0);
        visited[0] = true;
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
// we will always use this loop to traverse all the neighbour or degree of a particular node.           
            for(int i = 0; i<adj[node].size(); i++)
            {
                if(!visited[adj[node][i]]){
                    q.push( adj[node][i] );
                    visited[ adj[node][i] ] = true;
                }
            }
        }
        return ans;
    }