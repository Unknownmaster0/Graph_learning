#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/bipartite-graph/1

    bool solvedfs(int idx, vector<int>adj[], vector<int>& col, int incol){
        col[idx] = incol;
        
        for(auto it:adj[idx]){
            if(col[it] == col[idx]) return false;
            
            else if(col[it] == -1){
                if(solvedfs(it, adj, col, !incol) == false) return false;
            }
        }
        return true;
    }

    bool solvebfs(int idx, vector<int>adj[], vector<int>& col){

        queue<int> q;
        q.push(idx);
        
        col[idx] =  0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(col[it] == -1){
                    col[it] = !col[node];
                    q.push(it);
                }
                else{
                    if(col[it] == col[node]) return false;
                }
            }
        }
        return true;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    
	    // a graph is bipartite if every vertex of the graph can be coloured with two colour.
	    
	    vector<int> colored(V, -1);


// this for loop is needed to check for the component thing.
        for(int i = 0; i<V; i++){
            if(colored[i] == -1){
                // if(solvebfs(i, adj, colored) == false)    return false;
                if(solvedfs(i, adj, colored, 0) == false)    return false;
                else{
                    
                }
            }
        }
        return true;
	}

int main()
{
    
    return 0;
}