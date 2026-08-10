class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //bfs
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i =0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == '1'){
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();
                        for(auto dir : directions){
                            int nr = r+dir.first;
                            int nc = c+dir.second;
                            if(nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == '1'){
                                q.push({nr, nc});
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};