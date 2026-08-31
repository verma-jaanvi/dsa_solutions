class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int i = 0; i<= n; ++i)  dp[i][0] = 0;
        for(int j = 0; j<=m; ++j) dp[0][j] = 0;

        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                if(str1[i-1] == str2[j-1])  dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i = n, j = m;
        string ans = "";
        while(i >0 && j >0){
            if(str1[i-1] == str2[j-1]){
                ans = str1[i-1] + ans;
                i--; j--;
            }else if(dp[i][j-1] < dp[i-1][j]){
                ans = str1[i-1] + ans;
                i--;
            }else{
                ans = str2[j-1] + ans;
                j--;
            }
        }
        while(i>0)  ans = str1[--i] + ans;
        while(j > 0)    ans = str2[--j] + ans;
        return ans;
    }
};