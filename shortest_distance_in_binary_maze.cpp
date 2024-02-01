#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        
        distance[source.first][source.second] = 0;
        
        queue<pair<int,int>> q;
        q.push({source.first, source.second});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int i = 0; i<4; i++)
            {
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
                {
                    if(distance[nrow][ncol] > distance[row][col] + 1)
                    {
                        distance[nrow][ncol] = distance[row][col] + 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        
        if(distance[destination.first][destination.second] == INT_MAX)  return -1;
        
        return distance[destination.first][destination.second];
    }

int main()
{
    
    return 0;
}