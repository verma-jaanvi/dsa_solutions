class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        if(val == color)    return image;

        vector<vector<int>> ans = image;
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while(!q.empty()){
            pair<int, int> cell = q.front();
            q.pop();
            int i = cell.first, j =cell.second;
            // if(ans[i][j] == color)  continue;
            if(ans[i][j] == val){
                if(i > 0 && ans[i-1][j] == val) q.push({i-1, j});
                if(j > 0 && ans[i][j-1] == val) q.push({i, j-1});
                if(i < n-1 && ans[i+1][j] == val) q.push({i+1, j});
                if(j < m-1 && ans[i][j+1] == val) q.push({i, j+1});
                ans[i][j] = color;
            }
        }
        return ans;
    }
};