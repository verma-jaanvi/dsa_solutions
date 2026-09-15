class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i< n; ++i){
            for(int j = 0; j<m; ++j){
                if(mat[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0} , dc = {0, 0, -1, 1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i< 4; ++i){
                int nr = dr[i] + r, nc = dc[i] + c;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1){
                    ans[nr][nc] = ans[r][c] +1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};