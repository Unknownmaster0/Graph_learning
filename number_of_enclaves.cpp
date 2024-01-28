#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/number-of-enclaves/1
// same as replace O's with X's problem

    
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    
    void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        
        int tr = grid.size();
        int tc = grid[0].size();
        
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < tr && ncol >= 0 && ncol < tc && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int tr = grid.size();
        int tc = grid[0].size();
        
        vector<vector<int>> vis(tr, vector<int>(tc, 0));
        
        // now mark all the 1 that are at bourndary as visited.
        // search in 1st and last column
        for(int i = 0; i<tr; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i, 0, grid, vis);
            }
            if(grid[i][tc-1] == 1 && !vis[i][tc-1])
                dfs(i, tc-1, grid, vis);
        }
        
        for(int i = 0; i<tc; i++){
            if(grid[0][i] == 1 && !vis[0][i])
                dfs(0, i, grid, vis);
            if(grid[tr-1][i] == 1 && !vis[tr-1][i])
                dfs(tr-1, i, grid, vis);
        }
        
        int countEnclaves = 0;
        // now go and simply count the number of 1 in the between of matrix.
        for(int i = 0; i<tr; i++){
            for(int j = 0; j<tc; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    countEnclaves ++;
                }
            }
        }
        
        return countEnclaves;
    }

int main()
{
    
    return 0;
}