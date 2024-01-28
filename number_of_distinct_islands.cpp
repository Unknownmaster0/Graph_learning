#include<iostream>
#include<vector>
#include<set>
using namespace std;

// problem link->

/*This problem mainly teaches you how to store the shape in set data structure.
    You just make one node as base node and get substract all other nodes to the base node [coordinates of other nodes.]
*/

    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    
    void callDfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int,int>>& temp,int row0, int col0){
        vis[row][col] = 1;
        // here we are storing the different coordinates with respect to the base node. [row0 = base row coordinate , col0 = base col coordinate]
        temp.push_back({row-row0, col-col0});
        
        int tr = grid.size();
        int tc = grid[0].size();
        
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >=0 && nrow < tr && ncol >= 0&& ncol < tc && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                callDfs(nrow, ncol, vis, grid, temp, row0, col0);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int tr = grid.size();
        int tc = grid[0].size();
        
        vector<vector<int>> vis(tr, vector<int>(tc, 0));
        
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i<tr; i++){
            for(int j =0; j<tc; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int,int>>temp;
                    callDfs(i, j, vis, grid, temp, i, j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }

int main()
{
    
    return 0;
}