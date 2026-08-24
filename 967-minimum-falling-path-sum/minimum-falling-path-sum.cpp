class Solution {
public:
    int fn(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i == grid.size() -1)   return grid[i][j];
        if(dp[i][j] != -1)  return dp[i][j];
        int mini = fn(i+1, j, dp, grid);
        if(j>0) mini = min(mini, fn(i+1, j-1, dp, grid));
        if(j < grid.size()-1)   mini = min(mini, fn(i+1, j+1, dp, grid));

        return dp[i][j] = mini + grid[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = INT_MAX;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int i = 0; i<n; ++i){
        //     ans = min(ans, fn(0, i, dp, matrix));
        // }
        // return ans;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i =0; i<n; ++i) dp[0][i] =  matrix[0][i];

        for(int i = 1; i < n; ++i){
            for(int j = 0; j <n; ++j){
                if(j == 0)  dp[i][j]= min(dp[i-1][j], j < n-1 ? dp[i-1][j+1] : INT_MAX) + matrix[i][j];
                else if(j == n-1)   dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j];
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1])) + matrix[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; ++i)  ans = min(dp[n-1][i], ans);
        return ans;
        
    }
};