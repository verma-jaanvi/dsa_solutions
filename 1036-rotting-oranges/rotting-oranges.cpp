class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m ; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if (grid[i][j] == 1)
                    fresh++;
            }
            
        }

        vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        int ans = 0;
        while(!q.empty() && fresh > 0){
            int sz = q.size();
            while(sz--){
                auto [r, c] = q.front();
                q.pop();
                for(int i = 0; i< 4; ++i){
                    int nr = dr[i] + r, nc = dc[i] + c;
                    if(nr >= 0 && nr < n && nc>=0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            ans++;
            
        }
        return fresh == 0 ? ans : -1;
    }
};