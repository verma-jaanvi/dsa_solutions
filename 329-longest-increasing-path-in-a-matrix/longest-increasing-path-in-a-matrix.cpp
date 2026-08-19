class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {
        if(dp[r][c] != -1)  return dp[r][c];

        int n = matrix.size(), m = matrix[0].size();
        int val = matrix[r][c];
        int path = 1;

        if (r > 0) {
            int lt = matrix[r - 1][c];
            if (lt > val) {
                path = max(path, 1 + dfs(matrix, dp, r-1, c));
            }
        }
        if (c > 0) {
            int up = matrix[r][c - 1];
            if (up > val) {
                path = max(path, 1 + dfs(matrix, dp, r, c-1));
            }
        }
        if (r < n - 1) {
            int rt = matrix[r + 1][c];
            if (rt > val) {
                path = max(path, 1 + dfs(matrix, dp, r+1, c));
            }
        }
        if (c < m - 1) {
            int dn = matrix[r][c + 1];
            if (dn > val) {
                path = max(path, 1 + dfs(matrix, dp, r, c+1));
            }
        }

        dp[r][c] = path;
        return path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int cnt = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt = max(cnt, dfs(matrix, dp, i, j));
            }
        }
        return cnt;
    }
};