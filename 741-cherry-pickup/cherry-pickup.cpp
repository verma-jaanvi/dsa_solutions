class Solution {
public:
    int fn(int r1, int r2, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp){
        if(r1 <0 || r2 < 0 || j1<0 || j2 <0 || grid[r1][j1] == -1 || grid[r2][j2] == -1) return -1e9;

        if(dp[r1][r2][j1][j2] != -1)    return dp[r1][r2][j1][j2];

        if((r1 == 0 && j1 == 0))    return grid[r1][j1];

        int ans = 0;
        if(r1 == r2 && j1 == j2)    ans = grid[r1][j1];
        else ans = grid[r1][j1] + grid[r2][j2];

        ans += max(max(fn(r1-1, r2-1, j1, j2, grid, dp), fn(r1-1, r2, j1, j2-1, grid, dp)),
                   max(fn(r1, r2-1, j1-1, j2, grid, dp), fn(r1, r2, j1-1, j2-1, grid, dp)));
        return dp[r1][r2][j1][j2] = ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n , vector<int>(n, -1))));
        return max(0, fn(n-1, n-1, n-1, n-1, grid, dp));

    }
};