// Method - 1 (striver BFS)

#include <queue>
#include <vector>

void bfs(int row, int col, vector<vector<int>> &vis, int** grid){
    vis[row][col] = 1;
    int n = vis.size();
    int m = vis[0].size();
    
    queue<pair<int, int>> q;
    q.push({row, col});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        // transfer neighbours
        for(int dr=-1; dr<=1; dr++){
            for(int dc=-1; dc<=1; dc++){
                int nr = r+dr;
                int nc = c+dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m
                && grid[nr][nc] == 1 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
}

int getTotalIslands(int** grid, int n, int m)
{
   vector<vector<int>> vis(n ,vector<int> (m, 0));
   int count = 0;
   
   for(int r=0; r<n; r++){
       for(int c=0; c<m; c++){
           if(!vis[r][c] && grid[r][c]==1){
               count ++;
               bfs(r, c, vis, grid);
           }
       }
   }
   return count;
}



// Method - 2 (DFS)

#include<bits/stdc++.h>
vector<vector<int>> path= {{1,0}, {0,1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}, {0,-1}, {-1,0}};

void dfs(int **arr, int i,int j, int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j]==0) return;
    arr[i][j]=0;
    for(auto p: path){
        dfs(arr, i+p[0], j+p[1], n,m);
    }
    return;
}


int getTotalIslands(int** arr, int n, int m)
{
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                dfs(arr,i,j,n,m);
                cnt++;
            }
        }
    }
    return cnt;
}
