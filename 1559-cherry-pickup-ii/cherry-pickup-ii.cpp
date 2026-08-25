class Solution {
public:
    int fn(int r, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j1 <0 || j1 > grid[0].size()-1 || j2 <0 || j2 > grid[0].size() -1)   return 0;
        if(r == grid.size()-1){
            if(j1==j2)  return grid[r][j1];
            else return grid[r][j1] + grid[r][j2];
        }

        if(dp[r][j1][j2] != -1) return dp[r][j1][j2];

        int maxi = -1;
        for(int i =-1; i<=1; ++i){
            for(int j = -1; j<=1; ++j){
                if(j1 == j2)    maxi = max(maxi, grid[r][j1] + fn(r+1, j1+i, j2+j, grid, dp));
                else maxi = max(maxi, grid[r][j1] + grid[r][j2] + fn(r+1, j1+i, j2+j, grid, dp));
            }
        }
        return dp[r][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fn(0, 0, m-1, grid, dp);
    }
};