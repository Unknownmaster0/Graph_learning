#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

int main()
{
    
    return 0;
}

// time complexity -> O(n * m) + O(n * m * 4)
// space complexity -> O(n * m)

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    queue< pair< pair<int,int> , int > > q;
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    
	    // find all the nodes that have value 1.
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = 1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    vector<vector<int>> ans(n, vector<int>(m , 0));
	    int delrow[] = {-1,0,1,0};
	    int delcol[] = {0,1,0,-1};
	    
	    while(!q.empty()){
	        
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        
	        int dist = q.front().second;
	        q.pop();
	        
	        ans[row][col] = dist;
	        
	        for(int i = 0; i<4; i++){
	            
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
	                vis[nrow][ncol] = 1;
	                q.push({{nrow, ncol}, dist + 1});
	            }
	        }
	        
	    }
	    
	    return ans;
	}