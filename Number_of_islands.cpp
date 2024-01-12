#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    
    return 0;
}

// Dfs approach of solving the problem.
    void dfs(vector<vector<int>> &visited, int row, int col, vector<vector<char>>&grid)
    {
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        // now call dfs for the neighbouring elements.
        for(int i = -1; i<=1; i++)
        {
            for(int j = -1; j<=1; j++)
            {
                int nrow = row + i;
                int ncol = col + j;
                // cout<<"row -> "<<nrow<<" col -> "<<ncol<<endl;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol])
                {
                    visited[nrow][ncol] = 1;
                    dfs(visited, nrow, ncol, grid);
                }
            }
        }
    }



// BFS approach to solve this problem
    void bfs(vector<vector<int>> &visited, int row, int col, vector<vector<char>>& grid)
    {
        queue<pair<int,int>> store;
        
        store.push(make_pair(row,col));
        visited[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!store.empty())
        {
            pair<int,int> temp = store.front();
            store.pop();
            
            int i = temp.first;
            int j = temp.second;
            // push all the neighbouring node.
            /*
            // this is also the way of traversing all the 8 neighbour of the index but it have more number of lines to write.
            if(i-1 >= 0 && grid[i-1][j] != '0'  && !visited[i-1][j]){
                visited[i-1][j] = 1;
                store.push(make_pair(i-1,j));
            } 
            if(i-1 >= 0 && j+1 < grid[0].size() && grid[i-1][j+1] != '0' && !visited[i-1][j+1]){
                visited[i-1][j+1] = 1;
                store.push(make_pair(i-1,j+1));
            }
            if(j+1 < grid[0].size() && grid[i][j+1] != '0' && !visited[i][j+1]){
                visited[i][j+1] = 1;
                store.push(make_pair(i,j+1));
            }
            if(i+1 < grid.size() && j+1 < grid[0].size() && grid[i+1][j+1] != '0' && !visited[i+1][j+1]){
                visited[i+1][j+1] = 1;
                store.push(make_pair(i+1,j+1));
            }  
            if(i+1 < grid.size() && grid[i+1][j] != '0' && !visited[i+1][j]){
                visited[i+1][j]  = 1;
                store.push(make_pair(i+1,j));
            }
            if(i+1 < grid.size() && j-1 >= 0 && grid[i+1][j-1] != '0' && !visited[i+1][j-1]){
                visited[i+1][j-1] = 1;
                store.push(make_pair(i+1,j-1));
            }  
            if(j-1 >=0 && grid[i][j-1] != '0' && !visited[i][j-1]){
                visited[i][j-1] = 1;
                store.push(make_pair(i,j-1));
            }  
            if(i-1 >= 0 && j-1 >=0 && grid[i-1][j-1] != '0' && !visited[i-1][j-1])
            {
                visited[i-1][j-1] = 1;
                store.push(make_pair(i-1,j-1));
            }
            */
            // traversing all the neighbour in more fashionable way.
            for(int changeRow = -1; changeRow <= 1; changeRow ++)
            {
                for(int changeCol = -1; changeCol <= 1; changeCol ++)
                {
                    int nrow = i + changeRow;
                    int ncol = j + changeCol;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                    {
                        visited[nrow][ncol] = 1;
                        store.push({nrow,ncol});
                    }
                }
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // make a visited grid.
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        int countIsland = 0;
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(!visit[i][j] && grid[i][j] != '0'){
                    countIsland++;
                    bfs(visit, i, j, grid);
                }
            }
        }
        
        return countIsland;
    }