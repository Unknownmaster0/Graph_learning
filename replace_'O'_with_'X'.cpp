#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}

// overall time complexity -> O(n * m) [as in worst case when all the elements is O, then only 1 time dfs is called.]

// Time complexity -> O(n * m)
    void markedvisited(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& mat){

        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        // jo bhi connected O hai, wo sara visit ho jaye.
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                markedvisited(nrow, ncol, vis, mat);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // this can be done using the bfs and dfs both.
        vector<vector<char>> ans = mat;
        vector<vector<int>> vis(n , vector<int>(m, 0));
        
        // first traverse the boundary 'O' and marked them visited.
        // Time complexity -> O(N)
        for(int i = 0; i<n; i++){
            // first col
            if(mat[i][0] == 'O' && !vis[i][0]){
                markedvisited(i, 0, vis, mat);
            }
            // last col
            if(mat[i][m-1] == 'O' && !vis[i][m-1]){
                markedvisited(i, m-1, vis, mat);
            }
        }

        // Time complexity -> O(M)
        for(int i = 0; i<m; i++){
            // first row
            if(mat[0][i] == 'O' && !vis[0][i] ){
                markedvisited(0, i, vis, mat);
            }
            // last row
            if(mat[n-1][i] == 'O' && !vis[n-1][i]){
                markedvisited(n-1, i, vis, mat);
            }
        }
        
        // Time complexity -> O(N * M)
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(ans[i][j] == 'O' && !vis[i][j]){
                    ans[i][j] = 'X';
                }
            }
        }
        
        return ans;
    }
        