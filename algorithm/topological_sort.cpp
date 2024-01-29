#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/topological-sort/1

    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st)
    {
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        
        st.push(node);
    }
    
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> vis(V, 0);
        
        stack<int> st;
        
        for(int i = 0; i<V; i++)
        {
            if(!vis[i]) dfs(i, vis, adj, st);
        }
        
        // to store the nodes.
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}

int main()
{
    
    return 0;
}