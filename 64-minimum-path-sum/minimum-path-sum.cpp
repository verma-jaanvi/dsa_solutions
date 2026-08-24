class Solution {
public:

    int fn(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0)    return grid[i][j];
        if(i <0 || j < 0)   return INT_MAX;

        if(dp[i][j] != -1)  return dp[i][j];
        int a1 = fn(i-1, j, grid, dp);
        int a2 = fn(i, j-1, grid, dp);

        return min(a1, a2) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // return fn(n-1, m-1, grid, dp);

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(i == 0 && j == 0)    dp[i][j] = grid[i][j];
                else{
                    int a1 = i>0 ? grid[i][j] + dp[i-1][j] : INT_MAX;
                    int a2 = j>0 ? grid[i][j] + dp[i][j-1] : INT_MAX;
                    dp[i][j] = min(a1, a2);
                }
            }
        }
        return dp[n-1][m-1];
    }
};