class Solution {
public:
    int fn(vector<vector<int>> &dp, string &s, int i, int j){
        if(i >= j)  return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(s[i] == s[j])    return dp[i][j] = fn(dp,s, i+1, j-1);
        return dp[i][j] = min(fn(dp,s, i+1, j), fn(dp, s, i, j-1)) + 1;
    }

    int minInsertions(string s) {
        // preserve the order
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(dp, s, 0, n-1);
    }
};