#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/topological-sort/1

// Time complexity -> O(V + E) [same as dfs]
// space complexity -> O(V)

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

// Time complexity -> O(V + E) [same as BFS]

// space complexity -> O(V)
// topological sort -> using BFS known as KAHN's ALGORITHM
	vector<int> topoSort(int v, vector<int>adj[]){
	    
	    /******     KAHN'S ALGORITHM ******/
	    // find the indegree.
	    int indegree[v] = {0};
	    for(int i = 0; i<v; i++)
	    {
	        for(auto it:adj[i]){
	            indegree[it] ++;
	        }
	    }

	    // push nodes into queue whose indegree is 0.
	    queue<int> q;
	    for(int i = 0; i<v; i++)
	    {
	        if(indegree[i] == 0)    q.push(i);
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        if(indegree[node] == 0) ans.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it] --;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return ans;
	}

int main()
{
    
    return 0;
}