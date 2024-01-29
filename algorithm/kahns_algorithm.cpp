#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Time complexity -> O(V + E) [same as BFS]
// space complexity -> O(V)

/* when to apply topological sort algo (kahn's algo) -> 
                                        whenever in question it says that "something before something (prerequisite)" {then topological sort should comes in mind}
*/

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