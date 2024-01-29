#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

	bool isPossible(int v,int P, vector<pair<int, int> >& prerequisites) {
	    
	    // make the adjacency list. -> as first the tasks are not in the graph , then first make the graph.
	    
	    vector<int>adj[v];
	    
	    for(auto it:prerequisites){
	        
	        adj[it.second].push_back(it.first);
	    }
	    
	   // // print adjacency list
	   // for(int i = 0; i<v; i++){
	   //     cout<<"i -> "<<i<<" -> ";
	   //     for(auto it:adj[i]){
	   //         cout<<it<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    
	   // now use the KAHN's Algo
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
	    
        return (ans.size() == v ? true : false);
	}

int main()
{
    
    return 0;
}