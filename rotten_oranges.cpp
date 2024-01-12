#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

int main()
{
    
    return 0;
}

    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int trow = grid.size();
        int tcol = grid[0].size();
        
        queue<pair<pair<int,int> , int> > q;
        int vis[trow][tcol];
        
        int freshorange = 0;
        // pushing the initial rotten oranges to the queue and marked them visited into the vis array. Also count the freshoranges count.
        for(int i = 0; i<trow; i++){
            for(int j = 0; j<tcol; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 0;
                    freshorange ++;
                }
                else if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        
        // now do bfs.
        int cntfresh = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int maxtime = 0;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            
            q.pop();
            
            maxtime = max(maxtime, t);
            
            // go for the neighbouring nodes.
            for(int i = 0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
if(nrow >= 0 && nrow < trow && ncol >= 0 && ncol < tcol && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol}, t+1});
                    cntfresh++;
                }
            }
        }
        
        if(freshorange != cntfresh) return -1;
        
        return maxtime;
    }