// Space Optimized 
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<int> prev(m, 0);
    
    for(int i=0; i<n; i++){
        vector<int> cur(m, 0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) 
                cur[j] = grid[i][j];
            else{
                int up = grid[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left += cur[j-1];
                else left += 1e9;

                cur[j] = min(left, up);
            }
        }
        prev = cur;
    }
    return prev[m-1];
}



// Tabulation
#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < cols; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[rows - 1][cols - 1];
}
