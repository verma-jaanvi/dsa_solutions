class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i< n; ++i){
            for(int j = 0; j< m; ++j){
                if(grid[i][j] == '1'){
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if(r< n-1 && grid[r+1][c] == '1'){   
                            q.push({r+1, c});
                            grid[r+1][c] = '0';
                        }
                        if(c< m-1 && grid[r][c+1] == '1'){   
                            q.push({r, c+1});
                            grid[r][c+1] = '0';
                        }
                        if(r > 0 && grid[r-1][c] == '1'){   
                            q.push({r-1, c});
                            grid[r-1][c] = '0';
                        }
                        if(c > 0 && grid[r][c-1] == '1'){   
                            q.push({r, c-1});
                            grid[r][c-1] = '0';
                        }

                    }
                }
            }
        }
        return cnt;
    }
};