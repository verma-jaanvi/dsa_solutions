class Solution {
public:
    int fn(int i , int j, vector<vector<int>> &vec){
        if(i == vec.size()-1) return vec[i][j];
        int mini = fn(i+1, j, vec);
        // if(j>0) mini = min(mini, fn(i+1, j-1, vec));
        mini = min(mini, fn(i+1, j+1, vec));
        return mini + vec[i][j];

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        // return fn(0, 0, triangle);

        for(int i =1; i<n; ++i ){
            dp.push_back(vector<int>(triangle[i].size(), -1));
            for(int j=0; j< triangle[i].size(); j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][0] + triangle[i][j];
                }else if(j == i)    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) +triangle[i][j];
                }
            }
        }
        int ans = dp[n-1][0];
        for(int j = 1; j <n; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};