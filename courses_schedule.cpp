#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/course-schedule/1

/* approach -: if prerequisite tasks are able to possible then simply return the ans [which store topological sort oredering].
                else return {} [empty array].
*/

    vector<int> findOrder(int v, int m, vector<vector<int>> pre) 
    {
        	    // make the adjacency list.
	    
	    vector<int>adj[v];
	    
        for(int i = 0; i<m; i++)
        {
            int first = pre[i][0];
            int second = pre[i][1];
            
            adj[second].push_back(first);
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
	    
	    // if it is possible to finish all the tasks then only return the toposort ans, else return empty array.
	    if(ans.size() == v) return ans;
	    return {};
    }

int main()
{
    
    return 0;
}