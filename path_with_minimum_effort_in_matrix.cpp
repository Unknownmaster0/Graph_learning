#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

    int MinimumEffort(vector<vector<int>>& heights) {
        // when we come the shortest path question with source and destination then we can think of 
        // Dijkstra algorithm
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>> > , greater<pair<int,pair<int,int>>> > q;
        
        q.push({0,{0,0}});
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        
        while(!q.empty())
        {
            auto it = q.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            
            if(row == n-1 && col == m-1)    return diff;

            for(int i = 0; i<4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newdiff = abs(heights[nrow][ncol] - heights[row][col]);
                    
                    int eff = max(newdiff, diff);
                    
                    if(eff < effort[nrow][ncol]){
                        effort[nrow][ncol] = eff;
                        q.push({eff, {nrow, ncol}});
                    }
                }
            }
        }
        
        // return effort[n-1][m-1]; // you can also return after coming out of loop, but it will increase the number of iterations in the loop
        return 0;
    }

int main()
{
    
    return 0;
}